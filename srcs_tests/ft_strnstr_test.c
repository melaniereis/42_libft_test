/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_strnstr_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strnstr tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal substring search within length
    printf("%sTesting normal substring search within length:%s\n", BLUE, RESET);
    char *big1 = "Hello, World!";
    char *little1 = "World";
    
    char *result1 = ft_strnstr(big1, little1, 13); // Should return pointer to "World"
    char *result1_std = strnstr(big1, little1, 13); // Standard strnstr for comparison
    total_tests++;
    
    if (result1 != result1_std)
    {
        printf("%s[FAIL]%s ft_strnstr(\"%s\", \"%s\", 13) = \"%s\", expected \"%s\"\n", 
            RED, RESET, big1, little1, result1 ? result1 : "NULL", result1_std ? result1_std : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal substring search passed\n", GREEN, RESET);

    // Test case 2: Substring not found within length
    printf("\n%sTesting substring not found within length:%s\n", BLUE, RESET);
    
    char *result2 = ft_strnstr(big1, "x", 13); // Should return NULL
    char *result2_std = strnstr(big1, "x", 13); // Standard strnstr for comparison
    total_tests++;
    
    if (result2 != result2_std)
    {
        printf("%s[FAIL]%s ft_strnstr(\"%s\", \"x\", 13) should return NULL but got \"%s\"\n", 
            RED, RESET, big1, result2 ? result2 : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing substring not found passed\n", GREEN, RESET);

    // Test case 3: Length less than string length
    printf("\n%sTesting length less than string length:%s\n", BLUE, RESET);
    
    char *result3 = ft_strnstr(big1, little1, 5); // Should return NULL (not enough length)
    char *result3_std = strnstr(big1, little1, 5); // Standard strnstr for comparison
    total_tests++;
    
    if (result3 != result3_std)
    {
        printf("%s[FAIL]%s ft_strnstr(\"%s\", \"%s\", 5) should return NULL but got \"%s\"\n", 
            RED, RESET, big1, little1, result3 ? result3 : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing insufficient length passed\n", GREEN, RESET);

    // Test case 4: Search for empty substring
    printf("\n%sTesting search for empty substring:%s\n", BLUE, RESET);
    
    char *result4 = ft_strnstr(big1, "", 13); // Should return pointer to the beginning of big1
    char *result4_std = strnstr(big1, "", 13); // Standard strnstr for comparison
    total_tests++;
    
    if (result4 != result4_std)
    {
        printf("%s[FAIL]%s ft_strnstr(\"%s\", \"\", 13) should return \"%s\" but got \"%s\"\n", 
            RED, RESET, big1, big1, result4 ? result4 : "NULL");
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing empty substring passed\n", GREEN, RESET);

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

     save_test_results("ft_strnstr", total_tests, failed_tests);
}