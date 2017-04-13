/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/04/13 12:02:28 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			main(int argc, char **argv)
{
	int 	i;
	int		numTetri;
	char	**pieces;
	char	*board;

	i = -1;
	if (argc != 2)
	{
		ft_putstr("usage: \nfillit file\n");
		return (0);
	}
	argv++;
	numTetri = file_checker(*argv);
	if (!numTetri)
	{
		ft_putstr("error\n");
		return (0);
	}
	pieces = tetriTranslator(*argv, numTetri);
	if (!pieces)
	{
		ft_putstr("error\n");
		return (0);
	}
	board = ft_2dstrnew(BOARD_SIZE, BOARD_SIZE); 
	while (board[i++])
		ft_memset(board[i], (int)'.', BOARD_SIZE);
	Solve(board, 2, pieces, numTetri);
	return (0);
}
