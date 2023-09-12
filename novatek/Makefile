# nt9831x
#CROSS_TOOL  = arm-ca53-linux-gnueabihf-

# nt9832x
#CROSS_TOOL  = arm-ca9-linux-gnueabihf-

# nt98336/nt98633
#
CROSS_TOOL  = aarch64-ca53-linux-gnu-

CC = ${CROSS_TOOL}g++
CXXFLAGS = -Wall -O2
TARGET = main
OBJS = main.o

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
