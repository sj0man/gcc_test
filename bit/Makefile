CC = g++
CXXFLAGS = -Wall -O2
TARGET = id_path
OBJS = id_path.o

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
