#include <stdio.h>

int main(int ac, char **av)
{
	int i;
	int times;

	i = 0;

	if(ac == 2)
	{
		while((av[1][i] >= 65 && av[1][i] <= 90) || (av[1][i] >= 97 && av[1][i] <= 122))
		{
			if(av[1][i] >= 65 && av[1][i] <= 90)
			times = av[1][i] - 64;
			else
			times = av[1][i] - 96;
			while(times)
			{
				printf("%c", av[1][i]);
				times--;
			}
			i++;
		}
		printf("%c", av[1][i]);
	}
	printf("\n");
	return(0);
}
