CC ?= gcc
CCwin ?= x86_64-w64-mingw32-gcc
CFLAGS = -Wall -O2 -std=gnu17 -static
CFLAGSdebug = -Wall -O0 -std=gnu17 -static
TARGET = ZhengDeAI
OBJS = mainAI.o
OBJSwin = mainAI-win.c
.PHONY: clean
.PHONY: cleanwin
all: ZhengDeAI

ZhengDeAI: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)-release


Linuxdebug: $(OBJS)
	$(CC) $(CFLAGSdebug) $(OBJS) -o $(TARGET)-debug


win: $(OBJSwin)
	$(CCwin) $(CFLAGS) $(OBJSwin) -o $(TARGET)-release.exe


windebug: $(OBJSwin)
	$(CCwin) $(CFLAGSdebug) $(OBJSwin) -o $(TARGET)-debug.exe


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(TARGET) $(OBJS)