void		put_int_array(int **lst, int n, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= n)
	{
		if (lst[j] == NULL)
			ft_putstr("NULL");
		else
			while (i < l)
			{
				ft_putnbr(lst[j][i]);
				ft_putchar(' ');
				i++;
			}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	ft_putchar('\n');
}
