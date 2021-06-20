/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:03:41 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/19 15:04:15 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*quote_encode(char *line, int *i, char quote)
{
	int	save;
	int	end;

	*i += 1;
	save = *i;
	while (line[*i] != quote)
		(*i)++;
	end = *i;
	while (save != end)
	{
		if (line[save] == ';')
			line[save] = -1;
		else if (line[save] == '|')
			line[save] = -2;
		else if (line[save] == '<')
			line[save] = -3;
		else if (line[save] == '>')
			line[save] = -4;
		save++;
	}
	(*i)++;
	return (line);
}

char	*encode_lines(char *line)
{
	int		end;
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\'')
			line = quote_encode(line, &i, '\'');
		else if (line[i] == '\"')
			line = quote_encode(line, &i, '\"');
	}
	return (line);
}

char	**decode_lines(char **encode_lines)
{
	int	i;
	int	j;

	i = -1;
	while (encode_lines[++i])
	{
		j = -1;
		while (encode_lines[i][++j])
		{
			if (encode_lines[i][j] == -1)
				encode_lines[i][j] = ';';
			else if (encode_lines[i][j] == -2)
				encode_lines[i][j] = '|';
			else if (encode_lines[i][j] == -3)
				encode_lines[i][j] = '<';
			else if (encode_lines[i][j] == -4)
				encode_lines[i][j] = '>';
		}
	}
	return (encode_lines);
}
