/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:13:30 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 09:13:30 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c) //Define a function that returns the substrings count in a string seperated by a delimiter
{

}

static char	*get_next_word(char *s, char c) //Define a function that returns the new substring found within a string
{

}

char **split(char *s, char c) //Define a function that returns the substrings in a string seperated by a delimiter
{
    int words;
    char **total_array;
    int i = 0;
    // count words and return count. don't miss all preparation steps

    words = count_words(s, c);
    if(!words)
        exit(1);
    total_array = (char *)malloc(sizeof(words +2));
    if (!total_array)
        return NULL;
    total_array[i]


}