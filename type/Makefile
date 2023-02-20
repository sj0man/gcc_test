#CC = g++
#CC = aarch64-ca53-linux-gnu-g++
CC = arm-ca53-linux-gnueabihf-g++
CXXFLAGS = -Wall -O2 -fsigned-char
#CXXFLAGS = -Wall -O2
TARGET = main
OBJS = main.o


$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
