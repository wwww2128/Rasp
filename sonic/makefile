CC = gcc
CFLAG = -Wall
TARGET = us
OBJS = us1.o us2.o us3.o
LIBS = wiringPi

$(TARGET) : $OBJS
CC = gcc
CFLAG = -Wall
TARGET = us
OBJS = s1.o us2.o us3.o
LIBS = wiringPi

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -l$(LIBS)

us : us1.o us2.o us3.o
	gcc -o us us1.o us2.o us3.o -lwiringPi

us1.o : uSonic.c
	gcc -c -o us1.o uSonic.c
us2.o : us.c
	gcc -c -o us2.o us.c
us3.o : Trig.c
	gcc -c -o us3.o Trig.c
    
d : 
	rm -f *.o

song : song.c
	gcc -o song song.c -l$(LIBS)
