#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if(ac >= 2)
	{
		while(av[++j])
		{
			if(av[j][0] >= 'a' && av[j][0] <= 'z')
			{
				av[j][0] -= 32;
				write(1, &av[j][i], 1);
				i++;
			}
			else if(av[j][0] >= 'A' && av[j][0] <= 'Z')
			{
				write(1, &av[j][i], 1);
				i++;
			}
				
			while(av[j][i])
			{
				if(av[j][i] >= 'a' && av[j][i] <= 'z' && av[j][i - 1] == ' ')
					av[j][i] -= 32;
				else if(av[j][i] >= 'A' && av[j][i] <= 'Z' && av[j][i - 1] != ' ')
					av[j][i] += 32;
			
				write(1, &av[j][i], 1);
				i++;
			}
			i = 0;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}
