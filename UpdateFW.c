//gcc Update_FW.c -o Update_FW -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <pthread.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define B_RED     "\x1b[01;31m"
#define B_GREEN   "\x1b[01;32m"
#define B_YELLOW  "\x1b[01;33m"
#define B_BLUE    "\x1b[01;34m"
#define B_MAGENTA "\x1b[01;35m"
#define B_CYAN    "\x1b[01;36m"
#define BLINK        "\033[5m" //6

#define START_POSITION 11
#define BUFF_16 16
#define BUFF_3 3
#define BUFF_2 2

void gotoxy(uint8_t x, uint8_t y){
    //printf("\x1B[%d;%dH",y,x);
    //printf("\x1B[%d;%df",y,x);
    printf("\033[%d;%dH",y,x);
}

void clear(void){
    printf("\x1B[2J");
    //printf("\033[2J");
}

void Signal_Handler(int sign);
int Set_Interface_Attribs(int fd, int speed);
int Set_Mincount(int fd, int mcount);
void UART_Send(void);
void *UART_Receive(void *t);
void *User(void *t);


typedef struct{
    int id_dev;
    char dev[32];
    uint8_t tx[BUFF_16];
    uint8_t rx[BUFF_16];
    uint8_t buff_size;
    volatile uint8_t new_message;
} st_uart;

typedef struct{
    FILE *arq;
    uint16_t length;
    uint16_t position;
    uint32_t address;
    uint16_t cnt_word;
    uint16_t data;
    uint8_t is_data;
    volatile uint8_t active;
} st_firmware;

pthread_t thread_UART, thread_USER;
st_uart Uart;
st_firmware Firmware;
volatile unsigned short int running = 1;

int main(int argc, char **argv){
    uint8_t c = 0;
    uint16_t i;
    uint16_t size;
    uint16_t cnt_msn = 0;
    Uart.buff_size = BUFF_16;
    strcpy(Uart.dev,argv[1]);
    Uart.id_dev = open(Uart.dev, O_RDWR | O_NOCTTY | O_SYNC);
    if (Uart.id_dev < 0) {
        printf("Error opening %s: %s\n", Uart.dev, strerror(errno));
        return -1;
    }
    Set_Interface_Attribs(Uart.id_dev, B115200); // baudrate 115200, 8 bits, no parity, 1 stop bit
    signal(SIGINT, Signal_Handler);
    signal(SIGTERM, Signal_Handler);
    clear();
    if(pthread_create(&thread_UART, NULL, &UART_Receive, NULL) ) printf("\nErro thread uart\n");
    if(pthread_create(&thread_USER, NULL, &User, NULL) ) printf("\nErro thread user\n");

    //Firmware.arq = fopen("F28377S_Data_Flash.hex","rb");
    Firmware.arq = fopen(argv[2],"rb");
    if(Firmware.arq == NULL){
        perror("Error");
        return -1;
    }


    sleep(1);
    Uart.tx[14] = '\r';
    Uart.tx[15] = '\n';
    UART_Send();
    fseek(Firmware.arq, 0, SEEK_END);  // seek to end of file
    size = (ftell(Firmware.arq) - 4)>>1;        // get current file pointer
    fseek(Firmware.arq, 0, SEEK_SET);

    gotoxy(0,1); printf("Size: %d bytes\n", size);
    gotoxy(0,2); printf("[%4d]: %s", 0,"received");
    gotoxy(0,3); printf("Command: \n");


    Firmware.active = 0;
    while (running){
        if(Uart.new_message){
            gotoxy(0,4); printf("                         \n");
            gotoxy(0,2); printf("[%4d]: %s", ++cnt_msn,Uart.rx);
            gotoxy(0,3); printf("Command: \n");

            if(Firmware.active == 0 && Uart.rx[0] == 'U' && Uart.rx[1] == 'P' &&\
                Uart.rx[2] == 'F' && Uart.rx[3] == 'W' && Uart.rx[4] == '1'){
                Firmware.active = 1;
                gotoxy(0,4); printf("Enter modo UPDATE Firmware!\n");
                Uart.buff_size = BUFF_2;
            }
            Uart.new_message = 0;
        }

        if(Firmware.active == 1){
            Uart.rx[2] = '\0';
            i = Firmware.cnt_word = Firmware.is_data = 0;
            Firmware.position = START_POSITION;
            sleep(1);
            gotoxy(0,5); printf("Begin Update.\n");
            while(fread(&Firmware.data,sizeof(Firmware.data),1,Firmware.arq) == 1){
                if(Firmware.is_data){
                    if(Firmware.cnt_word == 0){
                        Uart.tx[0] = ((Firmware.length>>8) & 0x00FF);
                        Uart.tx[1] = (Firmware.length & 0x00FF);
                        Uart.tx[2] = 0x00;
                        UART_Send();
                        while(Uart.new_message == 0) usleep(25);
                        gotoxy(0,6); printf("Size [%04X]: %s \n", Firmware.length, (((Uart.rx[0] == Uart.tx[0]) && (Uart.rx[1] == Uart.tx[2])) ? "OK" : "Error"));
                        memset(Uart.rx,0,sizeof(Uart.rx));

                        Uart.tx[0] = ((Firmware.address>>24) & 0x000000FF);
                        Uart.tx[1] = ((Firmware.address>>16) & 0x000000FF);
                        Uart.tx[2] = 0x01;
                        UART_Send();
                        while(Uart.new_message == 0) usleep(25);
                        gotoxy(0,7); printf("Address [%08X] H: %s\n", Firmware.address, (((Uart.rx[0] == Uart.tx[0]) && (Uart.rx[1] == Uart.tx[2])) ? "OK" : "Error"));
                        memset(Uart.rx,0,sizeof(Uart.rx));

                        Uart.tx[0] = ((Firmware.address>>8) & 0x000000FF);
                        Uart.tx[1] = ((Firmware.address>>0) & 0x000000FF);
                        Uart.tx[2] = 0x02;
                        UART_Send();
                        while(Uart.new_message == 0) usleep(25);
                        gotoxy(0,8); printf("Address [%08X] L: %s\n", Firmware.address, (((Uart.rx[0] == Uart.tx[0]) && (Uart.rx[1] == Uart.tx[2])) ? "OK" : "Error"));
                        memset(Uart.rx,0,sizeof(Uart.rx));
                        //exit(0);
                    }

                    if(Firmware.cnt_word < Firmware.length){
                        Uart.tx[0] = ((Firmware.data>>8) & 0x000000FF);
                        Uart.tx[1] = ((Firmware.data>>0) & 0x000000FF);
                        Uart.tx[2] = 0x03;
                        UART_Send();
                        while(Uart.new_message == 0) usleep(10);
                        gotoxy(0,9); printf("Data [%04X]: %s [%.2f %%] \n", Firmware.data, (((Uart.rx[0] == Uart.tx[0]) && (Uart.rx[1] == Uart.tx[2])) ? "OK" : "Error"), 100.0*((float)i)/((float)size));
                        memset(Uart.rx,0,sizeof(Uart.rx));
                    }else{
                        Firmware.is_data = 0;
                    }
                    Firmware.cnt_word++;
                }
                // Read start of block (size,location, data)
                if(i == Firmware.position) Firmware.length = Firmware.data;
                else if(i == (Firmware.position + 1)) Firmware.address = (((unsigned int)Firmware.data) << 16) & 0xFFFF0000;
                else if(i == (Firmware.position + 2)){
                    Firmware.position += (Firmware.length + 3);
                    Firmware.address |= (Firmware.data & 0x0000FFFF);
                    //printf("[%d] = [%08X] [%04X] %d\n",i,Firmware.address, Firmware.length, Firmware.position);
                    Firmware.is_data = 1;
                    Firmware.cnt_word = 0;
                }
                i++;
            }
            Uart.tx[0] = 0xFF;
            Uart.tx[1] = 0xFF;
            Uart.tx[2] = 0xFF;
            UART_Send();
            usleep(100);
            UART_Send();
            Firmware.active = 0;
            break;
        }
    }
    fclose(Firmware.arq);
    close(Uart.id_dev);
    printf("\nStop program\n");
    return 0;
}

void Signal_Handler(int sign){
    int o_exit = 0;
    switch (sign){
    case SIGINT:{
        o_exit = 1;
        break;
    }
    case SIGTERM:{
        o_exit = 1;
        break;
    }
    default:{
        break;
    }
    }
    if (o_exit == 1)
        running = 0;
}

int Set_Interface_Attribs(int fd, int speed){
    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) {
        printf("Error from tcgetattr: %s\n", strerror(errno));
        return -1;
    }
    cfsetospeed(&tty, (speed_t)speed);
    cfsetispeed(&tty, (speed_t)speed);
    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;                 /* 8-bit characters */
    tty.c_cflag &= ~PARENB;             /* no parity bit */
    tty.c_cflag &= ~CSTOPB;             /* only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;            /* no hardware flowcontrol */
    /* setup for non-canonical mode */
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;
    /* fetch bytes as they become available */
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;
    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        printf("Error from tcsetattr: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

int Set_Mincount(int fd, int mcount){
    struct termios tty;
    if (tcgetattr(fd, &tty) < 0){
        printf("Error tcgetattr: %s\n", strerror(errno));
        return -1;
    }
    tty.c_cc[VMIN] = mcount ? 1 : 0;
    tty.c_cc[VTIME] = 5;        /* half second timer */
    if (tcsetattr(fd, TCSANOW, &tty) < 0){
        printf("Error tcsetattr: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

void UART_Send(void){
    if(Firmware.active == 0){
        write(Uart.id_dev,Uart.tx,BUFF_16);
        tcdrain(Uart.id_dev);
    }else{
        Uart.new_message = 0;
        write(Uart.id_dev,Uart.tx,BUFF_3);
        tcdrain(Uart.id_dev);
    }
}

void *UART_Receive(void *t){
    uint8_t i = 0;
    while(running){
        if(i < Uart.buff_size){
            read(Uart.id_dev,&Uart.rx[i++],1);
        }else{
            i = 0;
            Uart.new_message = 1;
        }
        while(Uart.new_message) usleep(50);
    }
}

void *User(void *t){
    uint8_t opc = 0;
    uint8_t cmd[16];
    while(running){
        gotoxy(0,3); printf("Command: \n");
        scanf("%s",Uart.tx);
        Uart.tx[14] = '\r';
        Uart.tx[15] = '\n';
        UART_Send();
        gotoxy(0,4); printf("                         \n");
    }
}
