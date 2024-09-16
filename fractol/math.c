#include "fractol.h"
#include "math.h"

double check_convergence(t_mlx mlx, t_vec z, t_vec c)
{
    int i;
    double  tmp_x;

    i = 0;
    while (i < mlx.f.max_i)
    {
        tmp_x = z.x;
        z.x = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * tmp_x * z.y + c.y;
        if((z.x * z.x + z.y * z.y) > mlx.f.radius * mlx.f.radius)
            return (i);
        i++;
    }
    return (0);

}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

char *check_space_fin(char *str)
{
    int i;
    int tmp;

    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
        {
            tmp = 1;
            i++;
        }
        if(tmp == 1)
            break;
        i++;
    }
    if(str[i] != '\0')
        return(str);
    else
    {
        i = 0;
        while (str[i] && str[i] != ' ')
            i++;
        str[i] = '\0';
    }
    return (str);
}

char *check_valid_number(char   *nbr)
{
    int i;
    char *var;
    char  *var2;

    i = 0;
    var = "+0";
    var2 = "-0";
    while (*nbr == ' ')
        nbr++;
    if((nbr[i] == '+' || nbr[i] == '-') && nbr[i+1] == '.')
    {
        if (nbr[i] == '+')
            nbr = ft_strjoin(var, nbr+1);
        if (nbr[i] == '-')
            nbr = ft_strjoin(var2, nbr+1);
    }
    else
        nbr = ft_strjoin(nbr,"");
    nbr = check_space_fin(nbr);
    return (nbr);
}
