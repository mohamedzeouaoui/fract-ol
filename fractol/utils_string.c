
#include "fractol.h"
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

static void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
            return (1);
        else
            return (0);
}


int	check_constant(char *x)
{
	int	i;
	int	pts;

	i = 0;
	pts = 0;
	x = check_valid_number(x);
	if ((x[i] == '-' || x[i] == '+') && x[i + 1] && ft_isdigit(x[i + 1]))
		i++;
	while (x[i])
	{
		if (ft_isdigit(x[i]) == 0 && (pts == 1 && x[i] == '.'))
			return (free(x),0);
		if (ft_isdigit(x[i]) == 0 && x[i] != '.')
			return (free(x),0);
		if (x[i] == '.')
			pts = 1;
		i++;
	}
	free(x);
	return (1);
}
