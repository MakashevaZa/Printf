#include "myprintf.h"

int ft_putstrd(char *str, t_list *lst)
{
    int i;
    int i2;
    int len;

    len = 0;
    i = 0;
    i2 = 0;
    if (lst->ispres && lst->precision < 0)
        lst->precision = 0;
    if (lst->align == 'l' && lst->filler == '0')
        lst->filler = ' ';
// FIXIT THE WIDTH OR PREC == -1
    if (lst->sign == 0)
    {
        
        if (lst->precision >= 0 && lst->precision < ft_strlen(str))
            len = lst->precision;
        else if (lst->precision == -1 || lst->precision >= ft_strlen(str))
            len = ft_strlen(str);
        if (lst->width == -1)
            lst->width = len;
    }
    if (lst->width <= len)
    {
        while (i < len)
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    else if (lst->width > len && lst->align == 'l')
    {
        while (i < len)
        {
            write(1, &str[i], 1);
            i++;
        }
        while (i < lst->width)
        {
            write(1, &(lst->filler), 1);
            i++;
        }
    }
    else if (lst->width > len && lst->align == 'r')
    {
        while (i < lst->width - len)
        {
            write(1, &(lst->filler), 1);
            i++;
        }
        while (i2 < len)
        {
            write(1, &str[i2], 1);
            i++;
            i2++;
        }
    }
    return (i);
}

int ft_putchard(int l, t_list *lst)
{
    write(1, &l, 1);
    return (1);
}


//printf("\n align %c filler %c .ispres %d precision %d sign %d width %d len %d\n", lst->align, lst->filler, lst->ispres, lst->precision, lst->sign, lst->width, len);
