CC = g++
CXXFLAGS = -Wall -O2 -DEXTRA_IPC
TARGET = main
OBJS = main.o

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
