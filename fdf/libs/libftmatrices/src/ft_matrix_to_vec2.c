/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_to_vec2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:33:59 by saeby             #+#    #+#             */
/*   Updated: 2022/12/15 18:39:39 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrices.h"

t_vector2	ft_matrix_to_vec2(float **m)
{
	t_vector2	v;

	v.x = m[0][0];
	v.y = m[1][0];
	ft_free_matrix(m, 1);
	return (v);
}