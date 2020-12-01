#include "myprintf.h"

static int		length_counter(unsigned long n)
{
	if (n > 15)
		return (1 + length_counter(n / 16));
	else
		return (1);
}

char			*ft_pitoa(unsigned long n, t_list *lst)
{
	int		length;
	char	*str;
	char *base1;
    
    base1 = "0123456789abcdef";
	length = length_counter(n) + 2;
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	str[length--] = '\0';
	while (length != -1)
	{
		str[length] = base1[n % 16];
		n = n / 16;
		length--;
	}
    str[0] = '0';
    str[1] = 'x';
	lst->sign = 1;
	return (str);
}