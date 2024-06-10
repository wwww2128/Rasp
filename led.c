#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// 핀 번호 정의
#define LED_PIN 0
#define BUTTON_PIN 1

void cleanup(int signum) {
    // LED 끄기
    digitalWrite(LED_PIN, LOW);
    printf("LED가 꺼졌습니다.\n");
    exit(0);
}

int main() {
    // WiringPi 라이브러리 초기화
    if (wiringPiSetup() == -1) {
        printf("WiringPi setup failed!\n");
        return 1;
    }

    // 핀 모드 설정
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    // SIGINT 신호 처리기 설정 (Ctrl+C)
    signal(SIGINT, cleanup);

    while (1) {
        // LED 켜기
        digitalWrite(LED_PIN, HIGH);
        delay(1000); // 1초 대기

        // LED 끄기
        digitalWrite(LED_PIN, LOW);
        delay(1000); // 1초 대기
    }

    return 0;
}
