CC = g++
CXXFLAGS = -Wall -O2
TARGET = fgets
OBJS = tmp.txt

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
