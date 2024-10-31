/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_strlen_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strlen tests          %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal string length
    printf("%sTesting normal string length:%s\n", BLUE, RESET);
    char *str1 = "Hello, World!";
    
    size_t result1 = ft_strlen(str1); // Should return 13
    size_t result1_std = strlen(str1); // Standard strlen for comparison
    total_tests++;
    
    if (result1 != result1_std)
    {
        printf("%s[FAIL]%s ft_strlen(\"%s\") = %zu, expected %zu\n", 
            RED, RESET, str1, result1, result1_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal string length passed\n", GREEN, RESET);

    // Test case 2: Empty string
    printf("\n%sTesting empty string:%s\n", BLUE, RESET);
    
    char *str2 = "";
    
    size_t result2 = ft_strlen(str2); // Should return 0
    size_t result2_std = strlen(str2); // Standard strlen for comparison
    total_tests++;
    
    if (result2 != result2_std)
    {
        printf("%s[FAIL]%s ft_strlen(\"%s\") = %zu, expected %zu\n", 
            RED, RESET, str2, result2, result2_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing empty string passed\n", GREEN, RESET);

    // Test case 3: String with spaces
    printf("\n%sTesting string with spaces:%s\n", BLUE, RESET);
    
    char *str3 = "   Leading and trailing spaces   ";
    
    size_t result3 = ft_strlen(str3); // Should return 35
    size_t result3_std = strlen(str3); // Standard strlen for comparison
    total_tests++;
    
    if (result3 != result3_std)
    {
        printf("%s[FAIL]%s ft_strlen(\"%s\") = %zu, expected %zu\n", 
            RED, RESET, str3, result3, result3_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing string with spaces passed\n", GREEN, RESET);

     // Test case 4: String with special characters
     printf("\n%sTesting string with special characters:%s\n", BLUE, RESET);
     
     char *str4 = "Hello! @#$%^&*()";
     
     size_t result4 = ft_strlen(str4); // Should return 17
     size_t result4_std = strlen(str4); // Standard strlen for comparison
     total_tests++;
     
     if (result4 != result4_std)
     {
         printf("%s[FAIL]%s ft_strlen(\"%s\") = %zu, expected %zu\n", 
             RED, RESET, str4, result4, result4_std);
         failed_tests++;
     }
     else
         printf("%s[OK]%s Testing special characters passed\n", GREEN, RESET);

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

     save_test_results("ft_strlen", total_tests, failed_tests);
}