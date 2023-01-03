CC = g++
CXXFLAGS = -Wall -O2
OBJS = sub.o main.o

%.o: %.c %.h
	$(CC) $(CXXFLAGS) -c $<

main : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o main

.PHONY: clean
clean :
	@rm -f $(OBJS) main

-include $(OBJS:.o=.d)
