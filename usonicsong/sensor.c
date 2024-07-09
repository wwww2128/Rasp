#include <stdio.h>
#include <wiringPi.h>

double Dist(int trigPin, int echoPin)
{
    // Trigger 신호 보내기
    digitalWrite(trigPin, 1);
    delayMicroseconds(10);
    digitalWrite(trigPin, 0);
    delayMicroseconds(200);

    // Echo 신호 대기
    while (digitalRead(echoPin) != 1); // ECHO HIGH 대기
    int t1 = micros(); // 시작 시간
    while (digitalRead(echoPin) != 0); // ECHO LOW 대기
    int t2 = micros(); // 종료 시간

    // 거리 계산
    return (t2 - t1) * 0.017; // 초음파 속도: 0.034 cm/us (왕복 거리)
}
