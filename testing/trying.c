/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:22:22 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/20 10:22:22 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

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

int main(void)
{
    char *word;
    while ((word = substring("15 33 44 annabelle love piero 12345678 1234567 123456     ", ' ')) != NULL)
    {
        printf("---> %s\n", word);
        free(word);
    }
    return 0;
}
