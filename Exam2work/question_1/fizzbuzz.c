#include "unistd.h"

int main (void)
{
    int i;
	int j;
	int k;

    i = 1;
	j = 1;
	k = 1;

    while (i <= 100)
    {
        if (i%3 == 0 && i%5 == 0)
            write(1, "fizzbuzz", 8);
		else if (i%3 == 0)
			write(1, "fizz" ,4);
		else if (i%5 == 0)
			write(1, "buzz", 4);
		else if(i < 10)
		{
		k = i + '0';
		write(1, &k ,1);
		}
		else
		{
			j = i / 10;
			k = i % 10;

			j = j + '0';
			k = k + '0';
			write(1, &j ,1);
			write(1, &k ,1);
		}
        i++;
		write(1, "\n" ,1);
    }
}