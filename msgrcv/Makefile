CC = gcc
CXXFLAGS = -Wall -O2
TARGET = msgrcv
OBJS = msgrcv.o

$(TARGET) : $(TARGET).c
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).c

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
