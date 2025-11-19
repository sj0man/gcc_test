CC = g++
CXXFLAGS = \
	-Wall \
	-O2 \
	-DEXTRA_IPC
#CXXFLAGS += -DNT9832X
CXXFLAGS += -DNT9831X

# definition 주석처리하려면 다중 라인 처리 대신, 하나씩 추가해서 주석 처리하면 된다.

TARGET = main
OBJS = main.o

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
