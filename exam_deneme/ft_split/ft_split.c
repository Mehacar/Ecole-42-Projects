#include <stdlib.h>

char **ft_split(char *str)
{
    char **split = (char **)malloc(1000);
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        split[k] = malloc(1000);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
        {
            split[k][j] = str[i];
            i++;
            j++;
        }
        split[k][j] = '\0';
        if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\0')
            k++;
        j = 0;
    }
    split[k] = NULL;
    return (split);
}
