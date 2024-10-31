/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

// Sample implementation of strtrim for comparison
char *standard_strtrim(const char *s, const char *set)
{
    if (!s || !set) return NULL;

    while (*s && strchr(set, *s))
        s++;
    
    const char *end = s + strlen(s);
    while (end > s && strchr(set, *(end - 1)))
        end--;

    size_t len = end - s;
    char *trimmed = malloc(len + 1);
    if (!trimmed) return NULL;

    strncpy(trimmed, s, len);
    trimmed[len] = '\0';
    
    return trimmed;
}

void ft_strtrim_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strtrim tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal trimming
    printf("%sTesting normal trimming:%s\n", BLUE, RESET);
    char *str1 = "   Hello, World!   ";
    char *set1 = " ";
    
    char *result1 = ft_strtrim(str1, set1); // Should return "Hello, World!"
    char *result1_std = standard_strtrim(str1, set1); // Standard strtrim for comparison
    total_tests++;
    
    if (strcmp(result1, result1_std) != 0)
    {
        printf("%s[FAIL]%s ft_strtrim(\"%s\", \"%s\") = \"%s\", expected \"%s\"\n", 
            RED, RESET, str1, set1, result1, result1_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal trimming passed\n", GREEN, RESET);
    
    free(result1); // Free allocated memory
    free(result1_std); // Free allocated memory

    // Test case 2: Trimming with multiple characters
    printf("\n%sTesting trimming with multiple characters:%s\n", BLUE, RESET);
    char *str2 = "---Hello---";
    char *set2 = "-";
    
    char *result2 = ft_strtrim(str2, set2); // Should return "Hello"
    char *result2_std = standard_strtrim(str2, set2); // Standard strtrim for comparison
    total_tests++;
    
    if (strcmp(result2, result2_std) != 0)
    {
        printf("%s[FAIL]%s ft_strtrim(\"%s\", \"%s\") = \"%s\", expected \"%s\"\n", 
            RED, RESET, str2, set2, result2, result2_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing multiple characters passed\n", GREEN, RESET);
    
    free(result2); // Free allocated memory
    free(result2_std); // Free allocated memory

    // Test case 3: No trimming needed
    printf("\n%sTesting no trimming needed:%s\n", BLUE, RESET);
    
    char *str3 = "Hello";
    
    char *result3 = ft_strtrim(str3, set1); // Should return "Hello"
    char *result3_std = standard_strtrim(str3, set1); // Standard strtrim for comparison
    total_tests++;
    
    if (strcmp(result3, result3_std) != 0)
    {
        printf("%s[FAIL]%s ft_strtrim(\"%s\", \"%s\") = \"%s\", expected \"%s\"\n", 
            RED, RESET, str3, set1, result3, result3_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing no trimming passed\n", GREEN, RESET);
    
    free(result3); // Free allocated memory
    free(result3_std); // Free allocated memory

    // Test case 4: Empty string input
    printf("\n%sTesting empty string input:%s\n", BLUE, RESET);
    
    char *result4 = ft_strtrim("", set2); // Should return ""
    char *result4_std = standard_strtrim("", set2); // Standard strtrim for comparison
    total_tests++;
    
    if (strcmp(result4, result4_std) != 0)
    {
        printf("%s[FAIL]%s ft_strtrim(\"\", \"%s\") = \"%s\", expected \"\"\n", 
            RED, RESET, set2, result4);
        failed_tests++;
    }
    
     free(result4); // Free allocated memory
     free(result4_std); // Free allocated memory

     // Test case 5: Null string input
     printf("\n%sTesting null string input:%s\n", BLUE, RESET);
     
     char *result5 = ft_strtrim(NULL, set2); // Should return NULL
     total_tests++;
     
     if (result5 != NULL)
     {
         printf("%s[FAIL]%s ft_strtrim(NULL) should return NULL but got a non-NULL pointer.\n", 
             RED, RESET);
         failed_tests++;
     }
     else
         printf("%s[OK]%s Testing null input passed\n", GREEN, RESET);

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

     save_test_results("ft_strtrim", total_tests, failed_tests);
}