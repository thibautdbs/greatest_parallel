/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:57:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 07:59:58 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

extern	SUITE(suite1);
extern	SUITE(suite2);

GREATEST_MAIN_DEFS();
int	main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(suite1);
    RUN_SUITE(suite2);

    GREATEST_MAIN_END();
}
