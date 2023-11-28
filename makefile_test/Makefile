CC = gcc
CXXFLAGS = -Wall -O2
TARGET = main
OBJS = main.o

CFG_FILE = my.cfg
MAX_COUNT = 10
BLK_SIZE = 1024

gen_param = \
	echo -e "name=$(1)" > $(2); \
	echo -e "payment=$(3)" >> $(2); \
	echo -e "sex=$(4)" >> $(2);

define rm_tmp_file
	if [ -f $(1) ]; then \
		rm $(1); \
	fi
endef

all :
	@echo "Building..."; \
	$(call gen_param,"leesj",$(CFG_FILE),$$(($(MAX_COUNT) * $(BLK_SIZE))),"female") \
	cat $(CFG_FILE); \
	echo "done";

	@$(call rm_tmp_file,$(CFG_FILE))

$(TARGET) : $(TARGET).c
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).c

.PHONY: clean
clean :
	@rm -f $(OBJS) $(TARGET)

-include $(OBJS:.o=.d)
