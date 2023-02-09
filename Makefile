# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 13:27:33 by tdubois           #+#    #+#              #
#    Updated: 2023/02/09 13:36:09 by tdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### CMDS

test: run_tests
	@./greatest_parallel ./run_tests;
.PHONY: test

test.verbose:
	@./greatest_parallel -v ./run_tests;
.PHONY: test.verbose

################################################################################
### TARGETS

SRCS		:=	main.c suite1.c suite2.c
INCLUDES	:=	greatest.h

run_tests: $(SRCS) $(INCLUDES)
	clang -Wall -Wextra -Werror -I. $(SRCS) -o $@;
