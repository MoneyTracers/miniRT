include sources.mk

#Compiler and Linker
CC          := cc

#The Target Binary Program
TARGET      := miniRT
TARGET_BONUS      := miniRT_bonus

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
INCDIR      := inc
OBJDIR      := build/obj
TARGETDIR   := build/bin
BUILDIR     := build
RESDIR      := res
SRCEXT      := c
OBJEXT      := o

#Bonus
OBJDIR_BONUS      := build_bonus/obj
TARGETDIR_BONUS   := build_bonus/bin
BUILDIR_BONUS     := build_bonus

#Flags, Libraries and Includes
CFLAGS      := -Wall -Werror -Wextra -I./inc -I./lib/libft/inc -g
LIB         := lib
LIBFT       := libft
LIBFT.A     := libft.a
MLX         := mlx_linux
MLX.A       := libmlx.a
#MLX_L_FLAGS := -Llib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
#MLX_C_FLAGS := -I/usr/include -Ilib/mlx_linux -Ilib/libft -O3
CFLAGS_BONUS      := -Wall -Werror -Wextra -DBONUS -I./inc -I./lib/libft/inc -g
DEBUG_FLAGS := -fsanitize=address -g

ifeq ($(shell uname), Darwin)
	MLX_L_FLAGS = -Llib/mlx_linux -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -lm
	MLX_C_FLAGS = -I/opt/X11/include -Ilib/mlx_linux  -Ilib/libft
else
	MLX_L_FLAGS = -Llib/mlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
	MLX_C_FLAGS = -I/usr/include -Ilib/mlx_linux -Ilib/libft
endif

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
OBJECTS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_BONUS     := $(patsubst $(SRCDIR)/%,$(OBJDIR_BONUS)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make

all: submodule build $(LIB)/$(MLX)/$(MLX.A) $(LIB)/$(LIBFT)/$(LIB)/$(LIBFT.A) $(TARGETDIR)/$(TARGET) 

#Remake
re: fclean all

debug: CFLAGS += -DDEBUG
debug: fclean all

#Prep submodules
submodule:
# 	git submodule update --init --recursive

#Make the Directories
build:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(OBJDIR)

#Clean only Objects
clean:
	@$(RM) -rf $(OBJDIR)
	@$(MAKE) -C $(LIB)/$(LIBFT) clean
	@$(MAKE) -C $(LIB)/$(MLX) clean

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(BUILDIR)
	@$(MAKE) -C $(LIB)/$(LIBFT) fclean
	@$(MAKE) -C $(LIB)/$(MLX) clean

#libft
$(LIB)/$(LIBFT)/$(LIB)/$(LIBFT.A):
	@$(MAKE) -C $(LIB)/$(LIBFT) all

#configure mlx
$(LIB)/$(MLX)/$(MLX.A):
	cd $(LIB)/$(MLX) && ./configure

#Link
$(TARGETDIR)/$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) $(MLX_L_FLAGS) $(LIB)/$(LIBFT)/$(LIB)/$(LIBFT.A) -o $(TARGETDIR)/$(TARGET)  -g

#Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo "Creating directory $(@D)"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MLX_C_FLAGS) -c -o $@ $^ -g

bonus: submodule build_bonus $(LIB)/$(MLX)/$(MLX.A) $(LIB)/$(LIBFT)/$(LIB)/$(LIBFT.A) $(TARGETDIR_BONUS)/$(TARGET_BONUS)

debug_bonus: CFLAGS_BONUS += -DDEBUG
debug_bonus: fclean bonus

re_bonus: fclean_bonus bonus

build_bonus:
	@mkdir -p $(TARGETDIR_BONUS)
	@mkdir -p $(OBJDIR_BONUS)

#Clean only Objects
clean_bonus:
	@$(RM) -rf $(OBJDIR_BONUS)
	@$(MAKE) -C $(LIB)/$(LIBFT) clean
	@$(MAKE) -C $(LIB)/$(MLX) clean

#Full Clean, Objects and Binaries
fclean_bonus: clean_bonus
	@$(RM) -rf $(BUILDIR_BONUS)
	@$(MAKE) -C $(LIB)/$(LIBFT) fclean
	@$(MAKE) -C $(LIB)/$(MLX) clean

#Link
$(TARGETDIR_BONUS)/$(TARGET_BONUS) : $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(MLX_L_FLAGS) $(LIB)/$(LIBFT)/$(LIB)/$(LIBFT.A) -o $(TARGETDIR_BONUS)/$(TARGET_BONUS)  -g

#Compile
$(OBJDIR_BONUS)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo "Creating directory $(@D)"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS_BONUS) $(MLX_C_FLAGS) -c -o $@ $^ -g

.PHONY: all re clean fclean lib
