/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:29:30 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/31 09:29:39 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

static int compare_splits(char **split1, char **split2)
{
    if (!split1 && !split2)
        return (1);
    if (!split1 || !split2)
        return (0);

    size_t i = 0;
    while (split1[i] && split2[i])
    {
        if (strcmp(split1[i], split2[i]) != 0)
            return (0);
        i++;
    }
    return (split1[i] == split2[i]);
}

static void free_split(char **split)
{
    if (!split)
        return;
    for (size_t i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

static char **standard_split(const char *str, char c)
{
    char **result;
    size_t count = 0;
    const char *tmp = str;

    while (*tmp)
    {
        if (*tmp != c)
        {
            count++;
            while (*tmp && *tmp != c)
                tmp++;
        }
        else
            tmp++;
    }

    result = malloc(sizeof(char *) * (count + 1));
    if (!result)
        return (NULL);

    size_t i = 0;
    while (*str)
    {
        if (*str != c)
        {
            const char *end = str;
            while (*end && *end != c)
                end++;
            size_t len = end - str;
            result[i] = malloc(len + 1);
            if (!result[i])
            {
                free_split(result);
                return (NULL);
            }
            memcpy(result[i], str, len);
            result[i][len] = '\0';
            i++;
            str = end;
        }
        else
            str++;
    }
    result[i] = NULL;
    return (result);
}

void ft_split_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_split tests           %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal string split
    printf("%sTesting normal string split:%s\n", BLUE, RESET);
    char *str1 = "Hello,World,Split,Test";
    char **result1 = ft_split(str1, ',');
    char **expected1 = standard_split(str1, ',');
    total_tests++;
    
    if (!compare_splits(result1, expected1))
    {
        printf("%s[FAIL]%s ft_split(\"%s\", ',') failed\n", RED, RESET, str1);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal string split passed\n", GREEN, RESET);

    free_split(result1);
    free_split(expected1);

    // Test case 2: Empty string
    printf("\n%sTesting empty string:%s\n", BLUE, RESET);
    char *str2 = "";
    char **result2 = ft_split(str2, ',');
    char **expected2 = standard_split(str2, ',');
    total_tests++;
    
    if (!compare_splits(result2, expected2))
    {
        printf("%s[FAIL]%s ft_split(\"\", ',') failed\n", RED, RESET);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing empty string passed\n", GREEN, RESET);

    free_split(result2);
    free_split(expected2);

    // Test case 3: String with no delimiter
    printf("\n%sTesting string with no delimiter:%s\n", BLUE, RESET);
    char *str3 = "NoDelimiterHere";
    char **result3 = ft_split(str3, ',');
    char **expected3 = standard_split(str3, ',');
    total_tests++;
    
    if (!compare_splits(result3, expected3))
    {
        printf("%s[FAIL]%s ft_split(\"%s\", ',') failed\n", RED, RESET, str3);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing string with no delimiter passed\n", GREEN, RESET);

    free_split(result3);
    free_split(expected3);

    // Test case 4: String with only delimiters
    printf("\n%sTesting string with only delimiters:%s\n", BLUE, RESET);
    char *str4 = ",,,,";
    char **result4 = ft_split(str4, ',');
    char **expected4 = standard_split(str4, ',');
    total_tests++;
    
    if (!compare_splits(result4, expected4))
    {
        printf("%s[FAIL]%s ft_split(\"%s\", ',') failed\n", RED, RESET, str4);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing string with only delimiters passed\n", GREEN, RESET);

    free_split(result4);
    free_split(expected4);

    // Test case 5: String with spaces as delimiter
    printf("\n%sTesting string with spaces as delimiter:%s\n", BLUE, RESET);
    char *str5 = "  Split  this string  ";
    char **result5 = ft_split(str5, ' ');
    char **expected5 = standard_split(str5, ' ');
    total_tests++;
    
    if (!compare_splits(result5, expected5))
    {
        printf("%s[FAIL]%s ft_split(\"%s\", ' ') failed\n", RED, RESET, str5);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing string with spaces as delimiter passed\n", GREEN, RESET);

    free_split(result5);
    free_split(expected5);

    // Print summary
    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s           SUMMARY              %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n", MAGENTA, RESET);
    
    printf("Total tests: %d\n", total_tests);
    
    if (failed_tests == 0)
        printf("%s✓ All tests passed!%s\n", GREEN, RESET);
    else
        printf("%s✗ Failed tests: %d%s\n", RED, failed_tests, RESET);

    printf("%s=================================%s\n\n", MAGENTA, RESET);

    save_test_results("ft_split", total_tests, failed_tests);
}
