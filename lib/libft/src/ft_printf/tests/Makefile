LIB_DIR := ../../ft_printf
LIB_ARC := libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =  ft_printftests_utils.c ft_printf_welcome.c ft_printf_tests/category_c.c \
		ft_printf_tests/test_util.c ft_printf_tests/category_d.c ft_printf_tests/category_i.c \
		ft_printf_tests/category_p.c ft_printf_tests/category_s.c ft_printf_tests/category_u.c \
		ft_printf_tests/category_x.c ft_printf_tests/category_X.c 

OBJS = $(SRCS:.c=.o)

NAME = ft_printftests.a

NORMINETTE = norminette_tester.sh
NORMDIR    = -d ../../
NORM_NO_PR = -npi


SRCDIR = ../src

SOURCES     := $(shell find $(SRCDIR) -type f -name "*.c")

.SILENT:

all: exe

exe: $(NAME) welcome logs norminette tests

exe_without_welcome: $(NAME) logs norminette tests

exe_welcome_lite: $(NAME) welcome_lite norminette logs tests

welcome_lite:
	cc -Wall -Werror -Wextra ft_printf_welcome_lite.c -o welcome_lite && ./welcome_lite 
	rm welcome_lite

welcome:
	cc -Wall -Werror -Wextra ft_printf_welcome.c -o welcome && ./welcome 
	rm welcome

logs:
	mkdir -p logs

norminette: 
	cd norminette_tester && bash $(NORMINETTE) $(NORMDIR)

tests:
	cc -Wall -Werror -Wextra ft_printftests.c ft_printftests.a $(LIB_DIR)/lib/$(LIB_ARC) && ./a.out
	rm a.out
	@$(MAKE) -s -C $(LIB_DIR) fclean

$(NAME): $(LIB_DIR)/$(LIB_ARC) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIB_DIR)/$(LIB_ARC): 
	@$(MAKE) -s -C $(LIB_DIR) all
	
 %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -s -C $(LIB_DIR) clean
	rm -rf logs
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -s -C $(LIB_DIR) fclean
	rm -f $(NAME)
	rm -rf *.txt

re: fclean all
