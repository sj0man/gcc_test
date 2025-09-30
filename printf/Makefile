CC = g++
# 64bit 빌드
CXXFLAGS = -Wall -O2

# 32bit 빌드
#CXXFLAGS = -Wall -O2 -m32


TARGET = fmt6
OBJS = $(TARGET).o

$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
