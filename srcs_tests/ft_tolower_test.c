/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_tolower_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_tolower tests        %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test lowercase letters
    printf("%sTesting lowercase letters (a-z):%s\n", BLUE, RESET);
    int c = 'a';
    while (c <= 'z')
    {
        total_tests++;
        int expected = c;  // ft_tolower should return the same character
        int result = ft_tolower(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_tolower('%c') = '%c', expected '%c'\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
        
        c++;
    }

    // Test uppercase letters
    printf("\n%sTesting uppercase letters (A-Z):%s\n", BLUE, RESET);
    c = 'A';
    while (c <= 'Z')
    {
        total_tests++;
        int expected = tolower(c);  // Use standard tolower for expected result
        int result = ft_tolower(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_tolower('%c') = '%c', expected '%c'\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
        
        c++;
    }

    // Test non-alphabetic characters
    printf("\n%sTesting non-alphabetic characters:%s\n", BLUE, RESET);
    char non_alpha[] = "0123456789!@#$%^&*()_+-=[]{}\\|;:'\",.<>?/ ";
    size_t i = 0; // Use size_t for index variable
    while (non_alpha[i])
    {
        total_tests++;
        int expected = non_alpha[i];  // Should return the same character
        int result = ft_tolower(non_alpha[i]);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_tolower('%c') = '%c', expected '%c'\n", 
                RED, RESET, non_alpha[i], result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, non_alpha[i]);
        
        i++;
    }

    // Additional edge case tests
    printf("\n%sTesting edge cases:%s\n", BLUE, RESET);

    // Test boundary values
    int boundary_cases[] = { -1, 0, 'A', 'Z', 'a', 'z', 128 };
    size_t j = 0; // Use size_t for index variable
    while (j < sizeof(boundary_cases) / sizeof(boundary_cases[0]))
    {
        total_tests++;
        int c = boundary_cases[j];
        
        // Expected outcome based on the character's case
        int expected;
        if (c >= 'A' && c <= 'Z')
            expected = tolower(c); // Convert to lowercase using standard tolower
        else if (c >= 'a' && c <= 'z')
            expected = c;          // Already lowercase
        else if (c >= 0 && c <= 127)
            expected = c;          // Non-alphabetic characters remain unchanged
        else
            expected = c;          // For values outside ASCII range

        int result = ft_tolower(c);
        
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_tolower(%d) = '%c', expected '%c'\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing value %d\n", GREEN, RESET, c);

        j++;
    }

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

     save_test_results("ft_tolower", total_tests, failed_tests);
}