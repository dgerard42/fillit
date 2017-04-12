/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:33:45 by esterna           #+#    #+#             */
/*   Updated: 2017/04/11 12:37:55 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			main(int argc, char **argv)
{
	int	numTetri;
	char **pieces;
	char *board;
	int boardSize;

	if (argc != 2)
	{
		ft_putstr("usage: \nur not using this shit correctly\n");
	}
	argv++;
	numTetri = file_checker(*argv);
	if (numTetri < 1)
		ft_putstr("error\n");
	pieces = tetriTranslator(*argv, numTetri);
	board = makeBoard();
	boardSize = 2;
	Solve(board, boardSize, pieces, numTetri);
	return (0);
}
