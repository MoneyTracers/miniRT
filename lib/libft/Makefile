LIB_DIR = src/libft
PRINT_DIR = src/ft_printf
GNL_DIR = src/get_next_line
LIB = lib

PRINT_A = libftprintf.a
GNL_A = get_next_line.a
NAME = libft.a
LIBFT = lib/libft.a

all: $(LIB) $(LIBFT)

$(LIB):
	mkdir -p lib
	
$(LIBFT): $(NAME) 

$(NAME): $(GNL_DIR)/$(GNL_A) $(PRINT_DIR)/$(PRINT_A) $(LIB_DIR)/$(NAME) 
	@if [ ! -f $(LIBFT) ]; then cp $(PRINT_DIR)/lib/$(PRINT_A) lib; cp $(GNL_DIR)/lib/$(GNL_A) lib; cp $(LIB_DIR)/lib/$(NAME) lib; ar -x lib/$(PRINT_A); mv *.o lib/; ar -x lib/$(GNL_A); mv *.o lib/; ar rcs lib/$(NAME) lib/*.o; rm lib/*.o; rm lib/$(PRINT_A); rm lib/$(GNL_A); fi

$(PRINT_DIR)/$(PRINT_A): 
	@$(MAKE) -C $(PRINT_DIR) all --no-print-directory

$(GNL_DIR)/$(GNL_A):
	@$(MAKE) -C $(GNL_DIR) all --no-print-directory

$(LIB_DIR)/$(NAME):
	@$(MAKE) -C $(LIB_DIR) all --no-print-directory

clean:
	@$(MAKE) -C $(PRINT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -f $(OBJS)
	@rm -f $(B-OBJS)

fclean: clean
	@$(MAKE) -C $(PRINT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(LIB_DIR) fclean
	@rm -f $(NAME)
	rm -rf lib 

re: fclean all

bonus: $(B-OBJS)
	ar rcs $(NAME) $(B-OBJS)