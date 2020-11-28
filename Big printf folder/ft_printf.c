#include "myprintf.h"

static int *type_handler(va_list ap, const char *str, int *array, t_list *lst)
{
    if (str[array[0]] == 'd' || str[array[0]] == 'i')
        array[1] += ft_putstrd(ft_itoa(va_arg(ap, int), lst), lst);
    if (str[array[0]] == 'u')
        array[1] += ft_putstrd(ft_uitoa(va_arg(ap, unsigned int)), lst);     
    if (str[array[0]] == 'x' || str[array[0]] == 'X')
        array[1] += ft_putstrd(ft_xitoa(str[array[0]], va_arg(ap, unsigned int)), lst);     
    if (str[array[0]] == 's')
        array[1] += ft_putstrd(va_arg(ap, char *), lst);
    if (str[array[0]] == 'c')
        array[1] += ft_putchard(va_arg(ap, int), lst);
    if (str[array[0]] == '%')
        array[1] += ft_putchard('%', lst);
    if (str[array[0]] == 'p')
        array[1] += ft_putstrd(ft_pitoa(va_arg(ap, unsigned long)), lst);
    array[0]++;
    return(array);
}

static int ft_istype(char c)
{
    char *types;

    types = "diuxXscp%";
    while (*types)
    {
        if (c == *types)
            return (1);
        types++;
    }
    return (0);
}

static int *args_handler(va_list ap, const char *str, int *array, t_list *lst)
{
    int i;

    while (!ft_istype(str[array[0]]))
    {
        if (str[array[0]] == '-')
        {
            lst->align = 'l';
            array[0]++;
        }
        if (str[array[0]] == '0')
        {
            lst->filler = '0';
            array[0]++;
        }
        if (str[array[0]] == '.')
        {
            lst->ispres = 1;
            array[0]++;
        }
        i = 0; 
        while (ft_isdigit(str[array[0]]))
        {
            i = i * 10 + str[array[0]] - '0';
            array[0]++;
        }
        if (lst->ispres == 1)
            lst->precision = i;
        else
            lst->width = i;
        if (str[array[0]] == '*' && lst->ispres == 1)
        {
            lst->precision = va_arg(ap, unsigned int); // FIXIT WITH PRECISION
            array[0]++;
        }
        else if (str[array[0]] == '*' && lst->ispres == 0)
        {    
            lst->width = va_arg(ap, unsigned int);
            array[0]++;
        }
        
    }
    return (type_handler(ap, str, array, lst));      
}

int ft_printf(const char *str, ...)
{
    va_list     ap;
    int array[2];
    char temp;
    t_list *lstnew;

    lstnew = ft_lstnew(); 
    array[0] = 0;
    array[1] = 0;
    va_start(ap, str);
    while (str[array[0]])
    {
        if (str[array[0]] != '%')
        {
            temp = str[array[0]++];
            write(1, &temp, 1);
            array[1]++;
        }
        else
        {
            array[0]++;
            args_handler(ap, str, array, lstnew);
        }
    }
    va_end(ap);
    return (array[1]);
}
