CC = gcc
CFLAGS = -W -Wall
TARGET = shop
DTARGET = shop_debug
OBJECTS = main.c product.c manager.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -c manager.c -o manager.o
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o
	rm shop shop_debug

