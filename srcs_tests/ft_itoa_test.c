/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../test.h"

void ft_itoa_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_itoa tests            %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal positive number
    printf("%sTesting normal positive number:%s\n", BLUE, RESET);
    
    char *result1 = ft_itoa(12345); // Should return "12345"
    char *expected1 = "12345";
    total_tests++;
    
    if (strcmp(result1, expected1) != 0)
    {
        printf("%s[FAIL]%s ft_itoa(12345) = \"%s\", expected \"%s\"\n", 
            RED, RESET, result1, expected1);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal positive number passed\n", GREEN, RESET);
    
    free(result1); // Free allocated memory

    // Test case 2: Zero
    printf("\n%sTesting zero:%s\n", BLUE, RESET);
    
    char *result2 = ft_itoa(0); // Should return "0"
    char *expected2 = "0";
    total_tests++;
    
    if (strcmp(result2, expected2) != 0)
    {
        printf("%s[FAIL]%s ft_itoa(0) = \"%s\", expected \"%s\"\n", 
            RED, RESET, result2, expected2);
        failed_tests++;
    }
    
     free(result2); // Free allocated memory

     // Test case 3: Normal negative number
     printf("\n%sTesting normal negative number:%s\n", BLUE, RESET);
     
     char *result3 = ft_itoa(-6789); // Should return "-6789"
     char *expected3 = "-6789";
     total_tests++;
     
     if (strcmp(result3, expected3) != 0)
     {
         printf("%s[FAIL]%s ft_itoa(-6789) = \"%s\", expected \"%s\"\n", 
             RED, RESET, result3, expected3);
         failed_tests++;
     }
     
     free(result3); // Free allocated memory

     // Test case 4: Minimum integer value
     printf("\n%sTesting minimum integer value:%s\n", BLUE, RESET);
     
     char *result4 = ft_itoa(-2147483648); // Should return "-2147483648"
     char *expected4 = "-2147483648";
     total_tests++;
     
     if (strcmp(result4, expected4) != 0)
     {
         printf("%s[FAIL]%s ft_itoa(-2147483648) = \"%s\", expected \"%s\"\n", 
             RED, RESET, result4, expected4);
         failed_tests++;
     }
     
     free(result4); // Free allocated memory

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

     save_test_results("ft_itoa", total_tests, failed_tests);
}