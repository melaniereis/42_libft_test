/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

// Sample function to be used with ft_strmapi
char sample_function(unsigned int index, char c)
{
    return c + index; // Example transformation: increment character by its index
}

void ft_strmapi_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strmapi tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal string transformation
    printf("%sTesting normal string transformation:%s\n", BLUE, RESET);
    char *str1 = "abc";
    
    char *result1 = ft_strmapi(str1, sample_function); // Should return "abc", "bcd", "cde"
    total_tests++;
    
    char expected_result1[4]; // +1 for null terminator
    expected_result1[0] = 'a' + 0; // 'a' + 0 -> 'a'
    expected_result1[1] = 'b' + 1; // 'b' + 1 -> 'c'
    expected_result1[2] = 'c' + 2; // 'c' + 2 -> 'e'
    expected_result1[3] = '\0'; // Null terminator

    if (strcmp(result1, expected_result1) != 0) // Expected output based on sample_function
    {
        printf("%s[FAIL]%s ft_strmapi(\"%s\") = \"%s\", expected \"%s\"\n", 
            RED, RESET, str1, result1, expected_result1);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal transformation passed\n", GREEN, RESET);
    
    free(result1); // Free allocated memory

    // Test case 2: Empty string input
    printf("\n%sTesting empty string input:%s\n", BLUE, RESET);
    
    char *result2 = ft_strmapi("", sample_function); // Should return ""
    total_tests++;
    
    if (strcmp(result2, "") != 0)
    {
        printf("%s[FAIL]%s ft_strmapi(\"\", sample_function) = \"%s\", expected \"\"\n", 
            RED, RESET, result2);
        failed_tests++;
    }
    
     free(result2); // Free allocated memory

     // Test case 3: Null string input
     printf("\n%sTesting null string input:%s\n", BLUE, RESET);
     
     char *result3 = ft_strmapi(NULL, sample_function); // Should return NULL
     total_tests++;
     
     if (result3 != NULL)
     {
         printf("%s[FAIL]%s ft_strmapi(NULL) should return NULL but got a non-NULL pointer.\n", 
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

     save_test_results("ft_strmapi", total_tests, failed_tests);
}