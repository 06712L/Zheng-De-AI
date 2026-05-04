CC ?= gcc
CCwin ?= x86_64-w64-mingw32-gcc
DEBUG ?= 0
CFLAGS := -Wall -std=gnu17 -static
ifeq ($(DEBUG),1)
CFLAGS += -O0 -g
O_DIR = oiia-debug
VERSION = debug
else
CFLAGS += -O2 -s
O_DIR = oiia
VERSION = release
endif
SRC_DIR = ./src
ELF_DIR = elf
EXE_DIR = exe
LIBS =
LIBSwin = -lwinmm
TARGET = ZhengDeAI
OBJS = ./$(O_DIR)/mainAI.o ./$(O_DIR)/boot.o
OBJSwin = ./$(O_DIR)/mainAI-win.o ./$(O_DIR)/boot-win.o
.PHONY: linux win cleanlinux cleanwin clean
all: linux

linux: $(OBJS)
	@mkdir -p $(ELF_DIR)
	@cp -n -r ./music ./$(ELF_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o ./$(ELF_DIR)/$(TARGET)-$(VERSION) $(LIBS)


win: $(OBJSwin)
	@mkdir -p $(EXE_DIR)
	@cp -n -r ./music-win ./$(EXE_DIR)
	$(CCwin) $(CFLAGS) $(OBJSwin) -o ./$(EXE_DIR)/$(TARGET)-$(VERSION).exe $(LIBSwin)


./$(O_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(O_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


./$(O_DIR)/%-win.o: $(SRC_DIR)/%-win.c
	@mkdir -p $(O_DIR)
	$(CCwin) $(CFLAGS) -c $< -o $@


cleanlinux:
	rm -rf ./$(ELF_DIR) $(OBJS)


cleanwin:
	rm -rf ./$(EXE_DIR) $(OBJSwin)

clean:
	rm -rf ./$(ELF_DIR) ./$(EXE_DIR) ./$(O_DIR)
