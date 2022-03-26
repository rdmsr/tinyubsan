TARGET ?= tinyubsan
SRC_DIRS ?= ./src
CC = gcc

SRCS := src/tinyubsan.c tests/test.c
OBJS := $(addsuffix .o,$(basename $(SRCS)))

CFLAGS ?= -ggdb -fsanitize=undefined -Wall -Wextra -Wno-builtin-declaration-mismatch
%.o: %.c
	@echo CC $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)

	@echo LD $@
	@$(CC) $(OBJS) -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) 

