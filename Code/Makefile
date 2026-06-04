CC     = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = quan_mi_cay
SRCS   = main.c global.c menu.c hoa_don.c
OBJS   = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) hoadon_*.txt

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
