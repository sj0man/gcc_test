CC = gcc
CXXFLAGS = -std=gnu11
TARGET = main
OBJS = main.o

$(TARGET) : $(TARGET).c
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).c

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
