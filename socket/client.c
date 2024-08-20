#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <wiringPi.h>

#define PORT 5005
#define LED_PIN 1 // WiringPi에서 GPIO 18은 핀 번호 1에 해당합니다

int main()
{
    struct sockaddr_in sad;
    memset(&sad, 0, sizeof(sad));
    
    sad.sin_family = AF_INET;
    sad.sin_port = htons(PORT);    
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); //127.0.0.1
    //printf("LE: %d    BE: %d\r\n",PORT, sad.sin_port);  
    unsigned int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("socket open result : %d....\r\n", fd);
    
    int addrLen = sizeof(sad);
    int ret = connect(fd, (struct sockaddr*)(&sad), addrLen);
    printf("client connect result : %d....\r\n", ret);

    // WiringPi setup
    if (wiringPiSetup() == -1) {
        printf("wiringPi setup failed\n");
        return 1;
    }

    pinMode(LED_PIN, OUTPUT);

    char buf[100];
    while(1)
    {
        printf("Message> ");
        scanf("%s", buf);
        write(fd, buf, strlen(buf));
        if(strcmp(buf, "exit") == 0) break;
        if(strcmp(buf, "LEDO") == 0) digitalWrite(LED_PIN, HIGH);
        if(strcmp(buf, "LEDX") == 0) digitalWrite(LED_PIN, LOW);
    }

    close(fd);
    return 0;
}
