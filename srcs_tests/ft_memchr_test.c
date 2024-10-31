/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void ft_memchr_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_memchr tests          %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal character search
    printf("%sTesting normal character search:%s\n", BLUE, RESET);
    char str1[] = "Hello, World!";
    
    char *result1 = ft_memchr(str1, 'W', sizeof(str1)); // Should return pointer to 'W'
    char *result1_std = memchr(str1, 'W', sizeof(str1)); // Standard memchr for comparison
    total_tests++;
    
    if (result1 != result1_std)
    {
        printf("%s[FAIL]%s ft_memchr(\"%s\", 'W', %zu) = \"%s\", expected \"%s\"\n", 
            RED, RESET, str1, sizeof(str1), result1 ? result1 : "NULL", result1_std ? result1_std : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal character search passed\n", GREEN, RESET);

    // Test case 2: Character not in string
    printf("\n%sTesting character not in string:%s\n", BLUE, RESET);
    
    char *result2 = ft_memchr(str1, 'x', sizeof(str1)); // Should return NULL
    char *result2_std = memchr(str1, 'x', sizeof(str1)); // Standard memchr for comparison
    total_tests++;
    
    if (result2 != result2_std)
    {
        printf("%s[FAIL]%s ft_memchr(\"%s\", 'x', %zu) should return NULL but got \"%s\"\n", 
            RED, RESET, str1, sizeof(str1), result2 ? result2 : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing character not found passed\n", GREEN, RESET);

    // Test case 3: Search for null terminator
    printf("\n%sTesting search for null terminator:%s\n", BLUE, RESET);
    
    char *result3 = ft_memchr(str1, '\0', sizeof(str1)); // Should return pointer to null terminator
    char *result3_std = memchr(str1, '\0', sizeof(str1)); // Standard memchr for comparison
    total_tests++;
    
    if (result3 != result3_std)
    {
        printf("%s[FAIL]%s ft_memchr(\"%s\", '\\0', %zu) = \"%s\", expected pointer to null terminator\n", 
            RED, RESET, str1, sizeof(str1), result3 ? result3 : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing null terminator search passed\n", GREEN, RESET);

    // Test case 4: Search for first character
    printf("\n%sTesting search for first character:%s\n", BLUE, RESET);
    
    char *result4 = ft_memchr(str1, 'H', sizeof(str1)); // Should return pointer to 'H'
    char *result4_std = memchr(str1, 'H', sizeof(str1)); // Standard memchr for comparison
    total_tests++;
    
    if (result4 != result4_std)
    {
        printf("%s[FAIL]%s ft_memchr(\"%s\", 'H', %zu) = \"%s\", expected \"%c\"\n", 
            RED, RESET, str1, sizeof(str1), result4 ? result4 : "NULL", 'H');
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing first character search passed\n", GREEN, RESET);

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

     save_test_results("ft_memchr", total_tests, failed_tests);
}