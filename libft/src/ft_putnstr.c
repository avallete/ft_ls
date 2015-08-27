#include <unistd.h>

void    ft_putnstr(char* str, unsigned int size)
{
    write(1, str, size);
}