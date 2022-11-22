#include <unistd.h>
#include <stdio.h>

int _putchar(char c)
{
	return(write(1, &c, 1));
}

void _print_d(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		_print_d(n / 10);
	}
	_putchar(n % 10 + '0');
}
int _print_s(char *s)
{
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			_putchar(s[i]);
			i++;
			/*continue;*/
		}
	}
	return (i);
}

int main(void)
{
	_print_s("this 001is my printf\n");
	_print_d(180);
	_print_s(":");
	return (0);
}
