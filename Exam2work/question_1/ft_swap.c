#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;
	printf("a 1.değeri :%p\n", a);
	tmp = *a;
	*a = *b;
	printf("a 2.değeri :%p\n", a);
	*b = tmp;

}

int main(void)
{
	int a;
	int b;

	a = 12;
	b = 45;

	printf("%p\n", &a);
	ft_swap(&a, &b);
	printf("%d\n", b);

	return(0);
}
