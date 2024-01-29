CC = g++
CXXFLAGS = -Wall -O2
TARGET = mkpool8
OBJS = mkpool8.o

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
