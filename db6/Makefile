CC = g++
CXXFLAGS = -Wall -O2
OBJS = main.o

main : main.c
	$(CC) $(CXXFLAGS) -o main main.c

.PHONY: clean
clean :
	@rm -f $(OBJS) main

-include $(OBJS:.o=.d)
