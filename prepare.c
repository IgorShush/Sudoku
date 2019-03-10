/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:08:41 by aimelda           #+#    #+#             */
/*   Updated: 2019/03/10 18:22:14 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		proverka(int i, int j, char **a);

void	ft_putstr(char *str)
{
	while (*(str++) != '\0')
		write(1, str - 1, 1);
}

int		initial(char **argv, int a[10][9])
{
	int		i;
	int		j;

	i = 0;
	while (++i <= 9)
	{
		j = -1;
		while (++j <= 8)
			if (argv[i][j] > 48 && argv[i][j] < 58)
			{
				a[i][j] = 1;
				if (!proverka(i, j, argv))
					return (1);
			}
			else if (argv[i][j] == '.')
				a[i][j] = 0;
			else
				return (1);
		if (argv[i][j] != '\0')
			return (1);
	}
	return (0);
}
