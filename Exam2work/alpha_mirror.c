#include <unistd.h>

int main(int ac, char **av)
{
	int i = -1;
	if (ac == 2)
    {
        while (av[1][++i])
        {
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 155 - av[1][i];
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 187 - av[1][i];
			write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return(0);
}
