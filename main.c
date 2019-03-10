/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimelda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:55:24 by aimelda           #+#    #+#             */
/*   Updated: 2019/03/10 18:21:37 by aimelda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);
int		initial(char **argv, int a[10][9]);

int		g_a[10][9];
char	*g_decis;
int		g_res;

void	save_dec(char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	g_decis = (char *)malloc(163 * sizeof(*g_decis));
	while (++i <= 9)
	{
		j = -1;
		while (++j <= 8)
		{
			g_decis[++k] = argv[i][j];
			g_decis[++k] = ' ';
		}
		g_decis[k] = '\n';
	}
	g_decis[k + 1] = '\0';
}

int		def_x_y(int i, int j)
{
	if (i < j + 3)
		return (j - 1);
	else if (i < j + 6)
		return (j + 3 - 1);
	else
		return (j + 6 - 1);
}

int		proverka(int i, int j, char **a)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = -1;
	while (++x <= 8)
		if ((a[i][x] == a[i][j] && x != j) ||
				(a[x + 1][j] == a[i][j] && x + 1 != i))
			return (0);
	x = def_x_y(i, 1);
	y = def_x_y(j, 0);
	x1 = x + 3;
	y1 = y + 3;
	while (++x <= x1)
	{
		while (++y <= y1)
			if (a[x][y] == a[i][j] && (x != i || y != j))
				return (0);
		y -= 4;
	}
	return (1);
}

void	perebor(int i, int j, char **argv, int var)
{
	if (!g_a[i][j])
	{
		while (++var <= 9 && g_res < 2)
		{
			argv[i][j] = var + 48;
			if (proverka(i, j, argv))
			{
				if (j < 8)
					perebor(i, j + 1, argv, 0);
				else if (i < 9)
					perebor(i + 1, 0, argv, 0);
				else if (++g_res == 1)
					save_dec(argv);
			}
		}
		argv[i][j] = '.';
	}
	else if (j < 8)
		perebor(i, j + 1, argv, 0);
	else if (i < 9)
		perebor(i + 1, 0, argv, 0);
	else if (++g_res == 1)
		save_dec(argv);
}

int		main(int argc, char **argv)
{
	int		err;

	g_res = 0;
	err = 0;
	if (argc == 10)
		err = initial(argv, g_a);
	else
		err = 1;
	if (!err)
		perebor(1, 0, argv, 0);
	if (err || g_res != 1)
		ft_putstr("Error\n");
	else
		ft_putstr(g_decis);
}
