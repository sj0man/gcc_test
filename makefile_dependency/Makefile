CC = g++
CXXFLAGS = -Wall -O2 -g
TARGET = main
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $(OBJ)

main.cpp: sub.cpp

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	$(CC) -MM $< > $*.d

.PHONY: clean
clean:
	@rm -f $(TARGET) $(OBJ) $(OBJ:.o=.d)

-include $(OBJ:.o=.d)