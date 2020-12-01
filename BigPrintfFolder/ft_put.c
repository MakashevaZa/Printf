#include "myprintf.h"

void ft_putchar(int l)
{
    write(1, &l, 1);
}

int ft_putstrd(char *str, t_list *lst)
{
    int i;
    int i2;
    int len;

    len = 0;
    i = 0;
    i2 = 0;
  //  if (lst->ispres && lst->precision < 0) 
   //     lst->precision = 0;
    if (lst->align == 'l' && lst->filler == '0')
        lst->filler = ' ';

    if (lst->sign == 0) // NOT D, I, U, X
    { // FLAG 0: flag '0' results in undefined behavior with 's' conversion specifier [-Wformat]
    //   printf("\n align %c filler %c .ispres %d precision %d sign %d width %d len %d\n", lst->align, lst->filler, lst->ispres, lst->precision, lst->sign, lst->width, len);

        if (!str)
                str = ft_strdup("(null)");
        if (lst->precision >= 0 && lst->precision < (int)ft_strlen(str))
            len = lst->precision; //CHECK WITH NULL
        else if (lst->precision >= (int)ft_strlen(str) || lst->precision == -1)
            len = ft_strlen(str);

        if (lst->width == -1)
            lst->width = len;
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
                //printf("1");
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
    else 
    {
        if (ft_strlen(str) == 1 && str[0] == '0' && lst->precision == 0 && lst->width <= 0)
            return (i);
        else if (ft_strlen(str) == 1 && str[0] == '0' && lst->precision == 0 && lst->width > 0)
            str = ft_strdup(" ");
        if (lst->precision != -1)
        {
            lst->filler = ' ';
            if (lst->precision <= (int)ft_strlen(str))
                len = ft_strlen(str) + (lst->sign == -1);
            else
                len = lst->precision + (lst->sign == -1);    
        }
        else if (lst->precision == -1 && lst->align == 'r' && lst->filler == '0')
            len = lst->width;
        else //if (lst->precision == -1 && lst->align == 'l')
            len = ft_strlen(str) + (lst->sign == -1);
        //flag '0' is ignored when flag '-' is present [-Wformat]
        if (lst->align == 'r' && lst->filler == '0')
            lst->filler = ' ';       
        if (lst->width <= len)
        {
            if (lst->sign == -1)
            {
                ft_putchar('-');
                i++;
                len--;
            }    
            while (len-- > (int)ft_strlen(str))
                {
                    ft_putchar('0');
                    i++;
                }
            while (*str)
                {
                    ft_putchar(*str);
                    i++;
                    str++;
                }
        }
        else if (lst->width > len && lst->align == 'l')
        {
            while (i < len)
            {
                if (lst->sign == -1)
                {
                    ft_putchar('-');
                    i++;
                    len--;
                }    
                while (len-- > (int)ft_strlen(str))
                {
                    ft_putchar('0');
                    i++;
                }
                while (*str)
                {
                    ft_putchar(*str);
                    i++;
                    str++;
                }
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
                if (lst->sign == -1)
                {
                    ft_putchar('-');
                    i++;
                    i2++;
                    len--;
                }    
                while (len-- > (int)ft_strlen(str))
                {
                    ft_putchar('0');
                    i++;
                    i2++;
                }
                while (*str)
                {
                    ft_putchar(*str);
                    i++;
                    str++;
                    i2++;
                }
            }
        }
        
        return (i);
    }
    
    
}

int ft_putchard(int l, t_list *lst)
{
    int i;

    i = 0;
    if (lst->align == 'r')
    {              
        while (i < lst->width - 1)
        {
            write(1, &lst->filler, 1);
            i++;
        }
        write(1, &l, 1); 
    }
    else
    {
        write(1, &l, 1);
        i++;        
        while (i < lst->width)
        {
            write(1, &lst->filler, 1);
            i++;
        }
    }    
    return (i);
}



