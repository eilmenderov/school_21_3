/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleida <vleida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:11:50 by vleida            #+#    #+#             */
/*   Updated: 2021/04/20 12:03:20 by vleida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					negative;
	unsigned long long	res;

	negative = 1;
	res = 0;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && res <= 9223372036854775800)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (res > 9223372036854775807 && negative == 1)
		return (-1);
	else if (res > 9223372036854775807 && negative == -1)
		return (0);
	return ((int)res * negative);
}
