CC ?= gcc
CFLAGS = -Wall -O2 -std=gnu17
TARGET = ZhengDeAI
OBJS = mainAI.o
.PHONY: clean
all: ZhengDeAI

ZhengDeAI: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)


%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(TARGET) $(OBJS)
