/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:53:21 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 11:58:00 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

TEST	test1(void)
{
	FAIL();
}

TEST	test2(void)
{
	PASS();
}

SUITE(suite1)
{
    RUN_TEST(test1);
    RUN_TEST(test2);
}
