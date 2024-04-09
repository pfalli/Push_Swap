/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:13:30 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 12:40:43 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c) //Define a function that returns the count of numbers given at STDIN
{
    int count = 0;
    int inside_word = 0;

    while (*s)
    {
        if(*s != c && inside_word == 0)
        {
            count++;
            inside_word = 1;
        }
        else if(*s == c)
            inside_word = 0;
        s++;
    }
    return count;
}

// static int to get back the s[i] where it was left 
static char	*substring(char *s, char c) //Define a function that returns the new substring found within a string
{
    char *substring;
    size_t length = 0;
    static int i = 0;
    int x = 0;

    // calculate length
    while (s[i] == c) // to check counting ' ' space, when it left previously
        i++;
    if (s[i] == '\0') // to stop infinite loop
        return NULL;
    while (s[i + length] != c && s[i + length] != '\0')
        length++;
    substring = malloc((length + 1) * sizeof(char));
    if(!substring)
        return NULL;
    while((s[i] != c) && s[i])
    {
        substring[x] = s[i];
        x++;
        i++;
    }
    substring[x] = '\0';
    return (substring);
}

char **split(char *s, char c) //Define a function that returns the substrings in a string seperated by a delimiter
{
    int words;
    char **total_array;
    int i = 0;

    words = count_words(s, c);
    if(!words)
        exit(1);
    total_array = malloc((words + 2) * sizeof(char*));
    if (!total_array)
        return NULL;
    while (words-- >= 0) // allocation for substring as well
    {   
        if (i == 0)
        {
            total_array[i] = malloc(sizeof(char));
            if (!total_array[i])
                return NULL;
            total_array[i++][0] = '\0';
        }
        total_array[i++] = substring(s, c);
    }
    total_array[i] = NULL;
    return (total_array);
}

//  int main(void)
//  {
//     char **total_array = split("15 33 44", ' ');
//     while (*total_array != NULL)
//     {
//          printf("%s\n", *total_array);
//          total_array++;
//     }
//     return (0);
//  }