#include "ft_printf.h"

int main(void)
{
	int	numOne;
	int	numTwo;

	numOne = printf("|%-1.4d|\n", 123);
	printf("--------------------\n");
	numTwo = ft_printf("|%-1.4d|\n", 123);
	printf("\n\n-------------------\n\n");
	printf("printf:    %d\n", numOne);
	printf("ft_printf: %d\n", numTwo);
	printf("\n\n\n\n--------FIN--------\n\n\n");
	system("leaks a.out");
    return (0);
}
