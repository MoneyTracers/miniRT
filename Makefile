include sources.mk

#Compiler and Linker
CC          := cc

#The Target Binary Program
TARGET      := miniRT

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
INCDIR      := inc
OBJDIR      := build/obj
TARGETDIR   := build/bin
BUILDIR     := build
RESDIR      := res
SRCEXT      := c
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Werror -Wextra -I./inc -g
LIB         := lib
LIBFT       := libft
LIBFT.A     := libft.a
MLX         := mlx_linux
MLX.A       := libmlx.a
#MLX_L_FLAGS := -Llib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
#MLX_C_FLAGS := -I/usr/include -Ilib/mlx_linux -Ilib/libft -O3
DEBUG_FLAGS := -fsanitize=address -g

ifeq ($(shell uname), Darwin)
	MLX_L_FLAGS = -Llib/mlx_linux -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -lm
	MLX_C_FLAGS = -I/opt/X11/include -Ilib/mlx_linux 
else
	MLX_L_FLAGS = -Llib/mlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
	MLX_C_FLAGS = -I/usr/include -Ilib/mlx_linux 
endif

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
OBJECTS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make

all: submodule build $(LIB)/$(MLX)/$(MLX.A) $(LIB)/$(LIBFT)/$(LIBFT.A) $(TARGETDIR)/$(TARGET) 

#Remake
re: fclean all

debug: CFLAGS += -DDEBUG
debug: fclean all

#Prep submodules
submodule:
	git submodule update --init --recursive

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
$(LIB)/$(LIBFT)/$(LIBFT.A):
	@$(MAKE) -C $(LIB)/$(LIBFT) all

#configure mlx
$(LIB)/$(MLX)/$(MLX.A):
	cd $(LIB)/$(MLX) && ./configure

#Link
$(TARGETDIR)/$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) $(MLX_L_FLAGS) $(LIB)/$(LIBFT)/$(LIBFT.A) -o $(TARGETDIR)/$(TARGET)  -g

#Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo "Creating directory $(@D)"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MLX_C_FLAGS) -c -o $@ $^ -g


#Non-File Targets
.PHONY: all re clean fclean lib
