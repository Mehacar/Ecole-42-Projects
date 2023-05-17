#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i;
	int j;

	if(ac == 4)
	{
		i = atoi(av[1]);
		j = atoi(av[3]);

		if(av[2][0] == '+')
			printf("+ operation:%d", i + j);
		else if(av[2][0] == '-')
			printf("+ operation:%d", i - j);
		else if(av[2][0] == '*')
			printf("+ operation:%d", i * j);
		else if(av[2][0] == '/')
			printf("+ operation:%d", i / j);
		else if(av[2][0] == '%')
			printf("+ operation:%d", i % j);
	}
	printf("\n");
	return(0);
}