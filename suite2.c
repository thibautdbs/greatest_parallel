/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:53:21 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 07:58:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

TEST	test1(void)
{
	PASS();
}

TEST	test2(void)
{
	PASS();
}

SUITE(suite2)
{
    RUN_TEST(test1);
    RUN_TEST(test2);
}
