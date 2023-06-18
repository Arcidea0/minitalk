PRINTF = libftprintf.a
NAMEC = client
NAMES = server
NAMECB = client_bonus
NAMESB = server_bonus
SRCC = client.c
SRCS = server.c
SRCCB = client_bonus.c
SRCSB = server_bonus.c
CC = cc
OBJC=$(SRCC:.c=.o)
OBJS=$(SRCS:.c=.o)
OBJCB=$(SRCCB:.c=.o)
OBJSB=$(SRCSB:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJC)
	make -C printf
	$(CC) $(OBJC) $(CFLAGS) printf/$(PRINTF) -o $(NAMEC)

$(NAMES): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) printf/$(PRINTF) -o $(NAMES)

bonus: $(NAMECB) $(NAMESB)

$(NAMECB): $(OBJCB)
	@make -C printf
	$(CC) $(OBJCB) $(CFLAGS) printf/$(PRINTF) -o $(NAMECB)

$(NAMESB): $(OBJSB)
	$(CC) $(OBJSB) $(CFLAGS) printf/$(PRINTF) -o $(NAMESB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C printf
	@rm -rf $(OBJC)
	@rm -rf $(OBJS)
	@rm -rf $(OBJCB)
	@rm -rf $(OBJSB)

fclean: clean
	@rm -rf $(NAMEC)
	@rm -rf $(NAMES)
	@rm -rf $(NAMECB)
	@rm -rf $(NAMESB)

re: fclean all

.PHONY : all clean fclean re bonus
