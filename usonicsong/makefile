CC = gcc
CFLAG = -lwiringPi

all: main

main: main.o sensor.o sound.o
	$(CC) -o main main.o sensor.o sound.o $(CFLAG)

main.o: main.c
	$(CC) -c main.c

sensor.o: sensor.c
	$(CC) -c sensor.c

sound.o: sound.c
	$(CC) -c sound.c

clean:
	rm -f *.o main
