CC ?= gcc
CCwin ?= x86_64-w64-mingw32-gcc
CFLAGS = -Wall -O2 -std=gnu17 -static
CFLAGSdebug = -Wall -O0 -std=gnu17 -static
CFLAGSwin = -Wall -O2 -std=gnu17 -static
CFLAGSwindebug = -Wall -O0 -std=gnu17 -static 
SRC_DIR = ./src
O_DIR = oiia
ELF_DIR = elf
EXE_DIR = exe
LIBSwin = -lwinmm
TARGET = ZhengDeAI
OBJS = ./$(O_DIR)/mainAI.o ./$(O_DIR)/boot.o
OBJSwin = ./$(O_DIR)/mainAI-win.o ./$(O_DIR)/boot-win.o
.PHONY: Linux Linuxdebug win windebug clean cleanwin cleanall
all: Linux

Linux: $(OBJS)
	@mkdir -p $(ELF_DIR)
	@cp -n -r ./music ./$(ELF_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o ./$(ELF_DIR)/$(TARGET)-release


Linuxdebug: $(OBJS)
	@mkdir -p $(ELF_DIR)
	@cp -n -r ./music ./$(ELF_DIR)
	$(CC) $(CFLAGSdebug) $(OBJS) -o ./$(ELF_DIR)/$(TARGET)-debug


win: $(OBJSwin)
	@mkdir -p $(EXE_DIR)
	@cp -n -r ./music-win ./$(EXE_DIR)
	$(CCwin) $(CFLAGSwin) $(OBJSwin) -o ./$(EXE_DIR)/$(TARGET)-release.exe $(LIBSwin)


windebug: $(OBJSwin)
	@mkdir -p $(EXE_DIR)
	@cp -n -r ./music-win ./$(EXE_DIR)
	$(CCwin) $(CFLAGSwindebug) $(OBJSwin) -o ./$(EXE_DIR)/$(TARGET)-debug.exe $(LIBSwin)


./$(O_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(O_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


./$(O_DIR)/%-win.o: $(SRC_DIR)/%-win.c
	@mkdir -p $(O_DIR)
	$(CCwin) $(CFLAGS) -c $< -o $@


clean:
	rm -rf ./$(ELF_DIR) $(OBJS)


cleanwin:
	rm -rf ./$(EXE_DIR) $(OBJSwin)

cleanall:
	rm -rf ./$(ELF_DIR) ./$(EXE_DIR) ./$(O_DIR)