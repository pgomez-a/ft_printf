#include "ft_printf.h"

int main(void)
{

	printf("|%0-8.5d|\n", 34);
	printf("--------------------\n");
	ft_printf("|%0-8.5d|\n", 34);
	printf("\n\n\n\n--------FIN--------\n\n\n");

	system("leaks a.out");
    return (0);
}
