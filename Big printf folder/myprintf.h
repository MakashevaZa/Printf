#ifndef MYPRINTF_H
# define MYPRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // FIXIT DONT FORGET TO REMOVEEEEEEEEE
typedef	struct		s_list
{
    char            align;
    unsigned int    width;
    char            filler;
    unsigned int    precision;
    int             ispres;
    int             sign;
}					t_list;
int	ft_isdigit(int c);
int                 ft_printf(const char *, ...);
size_t				ft_strlen(const char *n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_itoa(int n, t_list *lst);
char				*ft_uitoa(unsigned int n);
char				*ft_xitoa(char x, unsigned int n);
char			*ft_pitoa(unsigned long n);
int ft_putstrd(char *str, t_list *lst);
int ft_putchard(int l, t_list *lst);
t_list	*ft_lstnew(void);

#endif