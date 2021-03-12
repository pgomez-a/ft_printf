#include "ft_printf.h"

int main(void)
{
	char	*a01;


	printf("|%20p|\n",&a01);
	printf("--------------------\n");
	ft_printf("|%20p|\n",&a01);
	printf("\n\n\n\n--------FIN--------\n\n\n");

	//system("leaks a.out");
    return (0);
}
