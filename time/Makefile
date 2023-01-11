CC = g++
CXXFLAGS = -Wall -O2
OBJS = tm.o

tm : tm.c main.c
	$(CC) $(CXXFLAGS) -o tm tm.c
	$(CC) $(CXXFLAGS) -o main main.c

.PHONY: clean
clean :
	@rm -f $(OBJS) main tm

-include $(OBJS:.o=.d)
