#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define IN1 21
#define IN2 22
#define IN3 23
#define IN4 24

char* GetToken(char* str, char c, int n) // str:대상문자열, c:구분자, n:요소번호
{   //00 & 11 & 22 & 33 & 44     value=123   &    button=submit1    &    button=submit2&button=submit
	int i, i1 = 0, i2 = 0, cnt = 0;
	char* ret = (char*)malloc(50);
	for(i=0; i<strlen(str); i++)
	{
		if(str[i] == c) 
		{
			cnt++;
			if(cnt == n) 
			{
				i1 = i;  // 구분자 위치
			}
			else if(cnt == n+1)
			{
				i2 = i; // 
				if(i1) i1++;
				strncpy(ret,str+i1,i2-i1);
				return ret;
			}
		}
	}
	if(cnt < n) return NULL;

	i2 = i;//strlen(str); // 
	if(i1) i1++;
	strncpy(ret,str+i1,i2-i1);
	return ret;
}

void step_wave(int step) // 1000 0100 0010 0001
{
    switch (step)
    {
        case 0:
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            break;  // Add break to prevent fall-through
        case 1:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            break;
        case 2:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 0);
            break;
        case 3:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
            break;
    }
}

void step_full(int step) // 1100 0110 0011 1001
{
    switch (step)
    {
        case 0:
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            break;
        case 1:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 0);
            break;
        case 2:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 1);
            break;
        case 3:
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
            break;
    }
}

void step_half(int step) // 1100 - 0100 - 0110 - 0010 - 0011 - 0001 - 1001 - 1000
{
    switch (step)
    {
        case 0:
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            break;
        case 1:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            break;
        case 2:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 1);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 0);
            break;
        case 3:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 0);
            break;
        case 4:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 1);
            digitalWrite(IN4, 1);
            break;
        case 5:
            digitalWrite(IN1, 0);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
            break;
        case 6:
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 1);
            break;
        case 7:
            digitalWrite(IN1, 1);
            digitalWrite(IN2, 0);
            digitalWrite(IN3, 0);
            digitalWrite(IN4, 0);
            break;
    }
}

int steps[] = {4, 4, 8};

int main(int argc, char *s[]) //step 1 2000[n:CL의 단어 개수(=3), s:CL의 각 단어]
{
    
    char *qs = getenv("QUERY_STRING");	
    char *qs1 = GetToken(qs, '&', 0);  // value=1
    char *qs2 = GetToken(qs, '&', 1);  // value=10000

    char *ms = GetToken(qs1, '=', 1); 
    char *ts = GetToken(qs2, '=', 1);
    
    printf("Content-type: text/html\n\n");
    printf("<html>\n\n"); 	 
    printf("<h1>CGI controlled LED ON...</h1>\n");
    printf("<p>Remote Address : %s</p>\n", qs);
    printf("<p>Query String   : %s</p>\n", qs1);
    printf("<p>QS[0] : %s</p>", GetToken(qs1, '&', 0));
    printf("<p>QS[0,0] : %s</p>", GetToken(qs2, '=', 0));	// value
    printf("<p>QS[0,1] : %s</p>", GetToken(qs2, '=', 1));	// 11
    printf("<p>QS[1] : %s</p>", GetToken(qs1, '&', 1));
    printf("</html>\n\n"); 

    int mode = atoi(ms); // Fixed missing semicolon
    int msec = atoi(ts); 

    wiringPiSetup();
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    int t1 = micros();
    while(1)
    {
        for (int i = 0; i < steps[mode - 1]; i++) // steps is 0-based, mode is 1-based
        {
            switch (mode)
            {
                case 1: step_wave(i); break;
                case 2: step_full(i); break;
                case 3: step_half(i); break;
            }
            delay(5);
        }
        if((millis() - t1) > msec) break;
        
    }

    return 0;
}
