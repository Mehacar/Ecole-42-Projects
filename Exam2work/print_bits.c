#include <stdio.h>
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;

	while (i--)
	{
		bit = (octet >> i & 1);
		write(1, &"0123456789"[bit % 10], 1);
	}
}

int main(void)
{
	print_bits(1);
	printf("\n");
	print_bits(48);
	printf("\n");
	print_bits(3);
}
// you can learn bitwise from this video https://www.youtube.com/watch?v=jlQmeyce65Q Bitwise Operators in C (Part 1)