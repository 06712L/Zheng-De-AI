CC ?= gcc
CFLAGS = -Wall -O2 -std=gnu17
TARGET = ZhengDeAi
OBJS = mainAI.o
.PHONY: clean
all: ZhengDeAi

ZhengDeAi: $(OBJS)
	$(CC) $(CFLAGS) $(OBJD) -o $(TARGET)


%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(TARGET) $(OBJS)