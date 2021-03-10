#include "ft_printf.h"

int main(void)
{

	printf("|%07d|\n", -54);
	printf("--------------------\n");
	ft_printf("|%07d|\n", -54);
	printf("\n\n\n\n--------FIN--------\n\n\n");

	//system("leaks a.out");
    return (0);
}
