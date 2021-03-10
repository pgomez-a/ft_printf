#include "ft_printf.h"

int main(void)
{
	char	*a01;
	char	*a02;
	char	*a03;
	char	*a04;
	char	*a05;
	char	*a06;
	char	*a07;
	char	*a08;
	char	*a09;
	char	*a10;
	char	*a11;
	char	*a12;


	printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("--------------------\n");
	ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n\n\n\n--------FIN--------\n\n\n");

	//system("leaks a.out");
    return (0);
}
