#include "ft_printf.h"

int main(void)
{

	printf("|hello, %32s.|\n", NULL);
	printf("--------------------\n");
	ft_printf("|hello, %32s.|\n", NULL);
	printf("\n\n\n\n--------FIN--------\n\n\n");

	//system("leaks a.out");
    return (0);
}
