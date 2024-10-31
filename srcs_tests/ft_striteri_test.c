/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

// Sample function to be used with ft_striteri
static void sample_function(unsigned int index, char *c)
{
    *c = *c + index; // Example transformation: increment character by its index
}

void ft_striteri_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_striteri tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal string transformation
    printf("%sTesting normal string transformation:%s\n", BLUE, RESET);
    char str1[] = "abc"; // Original string
    
    ft_striteri(str1, sample_function); // Transform the string
    total_tests++;
    
    if (strcmp(str1, "ace") != 0) // Expected output based on sample_function
    {
        printf("%s[FAIL]%s ft_striteri(\"abc\") resulted in \"%s\", expected \"ace\"\n", 
            RED, RESET, str1);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal transformation passed\n", GREEN, RESET);

    // Test case 2: Empty string input
    printf("\n%sTesting empty string input:%s\n", BLUE, RESET);
    
    char str2[] = "";
    
    ft_striteri(str2, sample_function); // Should remain empty
    total_tests++;
    
    if (strcmp(str2, "") != 0)
    {
        printf("%s[FAIL]%s ft_striteri(\"%s\") resulted in \"%s\", expected \"\"\n", 
            RED, RESET, str2, str2);
        failed_tests++;
    }
    
    // Test case 3: Null string input
    printf("\n%sTesting null string input:%s\n", BLUE, RESET);
    
    char *str3 = NULL;
    
    // Here we need to check if ft_striteri handles NULL properly.
    // We expect it to do nothing and not crash.
    total_tests++; // Increment test count even though there's no output to check

    // Calling ft_striteri with NULL should not cause a crash.
    ft_striteri(str3, sample_function); 

    // Note: We can't check anything specific here since str3 is NULL.

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

     save_test_results("ft_striteri", total_tests, failed_tests);
}