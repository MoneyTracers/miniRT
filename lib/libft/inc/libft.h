/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:03:23 by spenning          #+#    #+#             */
/*   Updated: 2024/05/21 15:34:40 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These are header guards that prevent the double definitions in the 
// source file. This prevents library dependency from double copying
// libraries. if libft is already defined if won't define it again.
// name is LIBFT_H because the name should be the full filename of the 
// header file, in all caps, with underscores for spaces and ​punctuation.

#ifndef LIBFT_H
# define LIBFT_H

//these inclusions are needed to be able to use the write function from
// unistd library. and malloc and free from the stdlib library.

# include <stdlib.h>
# include <unistd.h>

// Bonus struct

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef DEBUG
#  define DEBUG 0
# endif

// string functions

// This function takes a pointer to s and creates a substring with len length 
// starting from start index. if start is longer than length of s, then 
// function will return empty string. If the length is bigger than length of 
// s starting from index start, then len will be adjusted to length of
// s starting from index start. This function returns a char * to allocated 
// substring, if allocations failed it will return NULL.
char	*ft_substr(char const *s, unsigned int start, size_t len);
// This function takes a pointer to s1 and creates a new string with 
// characters from set trimmed from beginning and end of s1. 
// If memory allocation fails function returns NULL otherwise function returns 
// trimmed string.
char	*ft_strtrim(char const *s1, char const *set);
// This function takes big and try to find little. if little is empty function
// returns big, If little is found then function returns a pointer to the 
// start of the first occurence of little. 
// Otherwise function returns NULL. 
char	*ft_strnstr(const char *big, const char *little, size_t len);
// This function takes s1 and compares s2 for n bytes. if s1 and s2 are equal 
// return value is 0, otherwise the difference in values of bytes being 
// compared in that moment is returned which is nonzero.
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// This function takes pointer char *s, and expects a null terminated string.
// then returns the length of the string.
size_t	ft_strlen(const char *s);
// This function copy size bytes from src to dst, function always returns the
// length of src. Function will keep on copying until it reaches size - 1,
// and there are still charachters to copy
// from src. Afterwards it null terminates the result.
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// This function takes dst, src, and n bytes (full buffer) 
// it needs to concatenate at the end. the size it should copy is always 
// size - dst_len - 1. If size is not bigger than dst, it cannnot concat
// therefore it returns the length of the string it wanted to create
// if the copy size is bigger than src len than it automatically makes
// the copy size equal to the size of src_len to not run of the string
// then after checking if there is enough space in dst and the amount it 
// copies from src is the maximum it can copy the memory with memcpy and
// null terminate the end.
size_t	ft_strlcat(char *dst, const char *src, size_t size);
// This function takes s1 and s2 and joins them together.
// if join fails or if malloc fails then function returns NULL.
char	*ft_strjoin(char const *s1, char const *s2);
// This functinos returns copy of s.
// If malloc fails it will return NULL.
// if string is empty it will still return
// copy of empty string.
char	*ft_strdup(const char *s);
// This function takes null terminated s and checks for c.
// function will return pointer to first instance found.
// if c is \0 it will still return a pointer to the null terminator in s
char	*ft_strchr(const char *s, int c);
// This function takes null terminated s and checks for c in reverse.
// function will return pointer to first instance found. 
// if c is \0 it will still return a pointer to the null terminator in s
char	*ft_strrchr(const char *s, int c);
// This function takes a char* nptr and it will return the int value 
// found in nptr. function skips whitespaces, returns both plus or minus
// values. If nptr is not well formated with multiple minusses or 
// charachters in between operators and number then it will return NULL
int		ft_atoi(const char *nptr);
// This function takes n and it will return a malloced string with the 
// string representation of n. if number is negative then it will first
// put a '-'. it will end. the function by null terminating the result.
// 0 value is also accepted. If malloc fails it will return NULL.
char	*ft_itoa(int n);
// This function takes input and converts input to uppercase equivalent
// if input was lowercase. Function returns conversion.
int		ft_toupper(int input);
// This function takes input and converts input to lowercase equivalent
// if input was uppercase. Function returns conversion.
int		ft_tolower(int input);
// This function takes null terminated s and splits s into multiple 
// string with delimiter c. amount of splits depend on amount of occurences
// of c. Function returns double char pointer 
// in which first array of pointers is ended with a NULL pointer, 
// and all strings are null terminated. If allocation fails then function 
// returns NULL.
char	**ft_split(char const *s, char c);

// memory functions

// This function takes a pointer to s and puts 0 for n consecutive memory 
// locations from the memory location pointed to by s. This function returns
// nothing.
void	ft_bzero(void *s, size_t n);
// This function takes a pointer to s and puts c for n consecutive memory 
// locations from the memory location pointed to by s. This function 
// returns nothing.
void	*ft_memset(void *s, int c, size_t n);
// This function takes a pointer to dest and puts data for n consecutive 
// memory locations from the memory location pointed to by src. Memory areas
// may overlap. Function is similar to memcpy.This function returns nothing.
void	*ft_memmove(void *dest, const void *src, size_t n);
// This function takes a pointer to dest and puts data for n consecutive 
// memory locations from the memory location pointed to by src. Memory areas
// may not overlap. if memory areas that need to be copied overlap then 
// memmove should be used. This function returns nothing.
void	*ft_memcpy(void *dest, const void *src, size_t n);
// This function takes a pointer to s1 and compares data for n consecutive
// memory locations from the memory location pointed to by s2. This function
// returns the difference in int values of the character compared which differ
// at the moment of comparison, if function returns 0 then n was 0 or memory
// was equal. pointer that is returned should later be freed with free()
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// This function takes a pointer to s and looks for n consecutive memory 
// locations for the c value. This function returns a void pointer to the 
// location at which c was found, or NULL if nothing was found.
void	*ft_memchr(const void *s, int c, size_t n);
// This function takes allocates memory for nmemb elments of size bytes and
// returns pointer to the allocated memory. If the multiplication of nmemb 
// and size causes a integer overflow then function will return NULL, same
// if allocation fails. pointer that is returned should later be 
// freed with free()
void	*ft_calloc(size_t nmemb, size_t size);
//This function is used to free a 2d char array, assuming the 2d array
// is null terminated. 
void	free_char_array(char **arr);

// is functions

// This function takes c and check if it is printable.
// returns nonzero if true, and zero if false.
int		ft_isprint(int c);
// This function takes c and check if it is a digit.
// returns nonzero if true, and zero if false.
int		ft_isdigit(int c);
// This function takes c and check if it is a ascii value.
// returns nonzero if true, and zero if false.
int		ft_isascii(int c);
// This function takes c and check if it is in the alphabet.
// returns nonzero if true, and zero if false.
int		ft_isalpha(int c);
// This function takes c and is equivalent of ft_isalpha || ft_isdigit.
// returns nonzero if true, and zero if false.
int		ft_isalnum(int c);

// write functions

// This function takes c and puts this c in fd file descriptor.
int		ft_putchar_fd(char c, int fd);
// This function takes char * s and puts this string in fd file descriptor.
// with \n charachter at the end of the string in the file descriptor
void	ft_putendl_fd(char *s, int fd);
// This function takes d and puts this integer value as a string in 
// fd file descriptor.
int		ft_putnbr_fd(int d, int fd);
// This function takes char *s and puts this string in fd file descriptor.
int		ft_putstr_fd(char *s, int fd);

// function pointers

// This function will accept a string and a function pointer.
// Then to each character of the string the function will be applied
// until we reach the null terminator of the string
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// this function created a new string based on s, and then applies f
// function to every character in the new string that is based on s.
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));

// printf function

// This function prints out the format string + variables 
// depending on which format specifiers are given. For example:
// ft_printf("Hello %s", s1);
// accepted formatters:
// %s	=	char*
// %d	=	int
// %i	=	int
// %p	=	void*
// %u	=	unsigned int
// %x	=	int
// %X	=	int 
int		ft_printf(const char *format, ...);

// get_next line

//This function returns a null terminated string which represents
//a line from the file descriptor (fd) given.Since the function 
//uses the read system call function, it will remember where it 
//left of reading in the file descriptor. It can be called with
// -D BUFFER_SIZE=(int) to increase the buffer size that is read.
char	*get_next_line(int fd, int free_buf);

// debug

//[Description]
//This function used to debug, if during compilation the debug flag is used
// parameters are the same as ft_printf
// with -D DEBUG=1
//[Parameters]
//char *format
//variables
//[Return]
//function returns nothing
//[Error]
// No error value
void	ft_debug(char *format, ...);

// bonus functions

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
