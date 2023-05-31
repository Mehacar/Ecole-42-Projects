#include <stdio.h>

int ft_atoi (const char *str)
{
    int i = 0;
    int num = 0;
    int neg = 1;

    while(str[i] == ' ' || str[i] == '\t')
        i++;
    if(str[i] == '-')
        neg *= -1;


    while(str[i] && str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0'); 
        i++;
    }
    return(num * neg);
}

int main(void)
{
    const char *str = "  201h,9";
    printf("num = %d\n", ft_atoi(str));
}