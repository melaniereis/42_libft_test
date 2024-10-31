/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_strncmp_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strncmp tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal comparison
    printf("%sTesting normal comparison:%s\n", BLUE, RESET);
    char *str1 = "Hello";
    char *str2 = "Hello";
    
    int result1 = ft_strncmp(str1, str2, 5); // Should return 0
    int result1_std = strncmp(str1, str2, 5); // Standard strncmp for comparison
    total_tests++;
    
    if (result1 != result1_std)
    {
        printf("%s[FAIL]%s ft_strncmp(\"%s\", \"%s\", 5) = %d, expected %d\n", 
            RED, RESET, str1, str2, result1, result1_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal comparison passed\n", GREEN, RESET);

    // Test case 2: Different strings
    printf("\n%sTesting different strings:%s\n", BLUE, RESET);
    
    char *str3 = "Hello";
    char *str4 = "Hella";
    
    int result2 = ft_strncmp(str3, str4, 5); // Should return positive value
    int result2_std = strncmp(str3, str4, 5); // Standard strncmp for comparison
    total_tests++;
    
    if (result2 <= 0 || result2 != result2_std)
    {
        printf("%s[FAIL]%s ft_strncmp(\"%s\", \"%s\", 5) should return positive but got %d\n", 
            RED, RESET, str3, str4, result2);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing different strings passed\n", GREEN, RESET);

    // Test case 3: Comparison with different lengths
    printf("\n%sTesting comparison with different lengths:%s\n", BLUE, RESET);
    
    char *str5 = "Hello";
    
    int result3 = ft_strncmp(str5, "Hellooo", 5); // Should return 0
    int result3_std = strncmp(str5, "Hellooo", 5); // Standard strncmp for comparison
    total_tests++;
    
    if (result3 != result3_std)
    {
        printf("%s[FAIL]%s ft_strncmp(\"%s\", \"Hellooo\", 5) = %d, expected %d\n", 
            RED, RESET, str5, result3, result3_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing comparison with different lengths passed\n", GREEN, RESET);

     // Test case 4: Comparison with zero length
     printf("\n%sTesting comparison with zero length:%s\n", BLUE, RESET);
     
     int result4 = ft_strncmp(str5, "Hellooo", 0); // Should return 0
     int result4_std = strncmp(str5, "Hellooo", 0); // Standard strncmp for comparison
     total_tests++;
     
     if (result4 != result4_std)
     {
         printf("%s[FAIL]%s ft_strncmp(\"%s\", \"Hellooo\", 0) = %d, expected %d\n", 
             RED, RESET, str5, result4, result4_std);
         failed_tests++;
     }
     else
         printf("%s[OK]%s Testing zero length comparison passed\n", GREEN, RESET);

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

     save_test_results("ft_strncmp", total_tests, failed_tests);
}