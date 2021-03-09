#include "ft_printf.h"

static int	pf_pct(va_list *ap, int ct, const char *format)
{
	char	*width;

	ct++;
	ct = pf_man_fmt(ap, ct, format, &width);
	if (format[ct] == 'c')
		pf_find_char(ap, &width);
	else if (format[ct] == '%')
		pf_find_pct(&width);
	else if (format[ct] == 's')
		pf_find_str(ap, &width);
	free(width);
	return (ct + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	ct;

	va_start(ap, format);
	ct = 0;
	while (format[ct])
	{
		if (format[ct] == '%')
			ct = pf_pct(&ap, ct, format);
		else
		{
			ft_putchar_fd(format[ct], 1);
			ct++;
		}
	}
	va_end(ap);
	return (0);
}
