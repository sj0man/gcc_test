CC = g++
CXXFLAGS = -Wall -O2
TARGET = sizeck
OBJS = main.o
BUILD_COMPLETE_STRING ?= $(shell date "+%a, %d %b %Y %T %z")


$(TARGET) : $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp
	@echo "Finish generating image at $(BUILD_COMPLETE_STRING)"
	@echo

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
