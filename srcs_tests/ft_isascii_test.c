/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void ft_isascii_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_isascii tests        %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test ASCII characters (0-127)
    printf("%sTesting ASCII characters (0-127):%s\n", BLUE, RESET);
    for (int c = 0; c < 128; c++)
    {
        total_tests++;
        int expected = isascii(c) ? 1 : 0;  // Expected outcome based on standard isascii
        int result = ft_isascii(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isascii(%d) = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
        {
            printf("%s[OK]%s Testing value %d\n", GREEN, RESET, c);
        }
    }

    // Test non-ASCII characters (128-255)
    printf("\n%sTesting non-ASCII characters (128-255):%s\n", BLUE, RESET);
    for (int c = 128; c < 256; c++)
    {
        total_tests++;
        int expected = isascii(c) ? 1 : 0;  // Expected outcome based on standard isascii
        int result = ft_isascii(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isascii(%d) = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
        {
            printf("%s[OK]%s Testing value %d\n", GREEN, RESET, c);
        }
    }

    // Additional edge case tests
    printf("\n%sTesting edge cases:%s\n", BLUE, RESET);

    // Test boundary values
    int boundary_cases[] = { -1, 0, 127, 128 };
    size_t i = 0; // Change to size_t to match sizeof return type
    while (i < sizeof(boundary_cases) / sizeof(boundary_cases[0]))
    {
        total_tests++;
        int test_value = boundary_cases[i];
        int expected = (test_value >= 0 && test_value <= 127) ? 1 : 0; // Expected outcome based on ASCII range
        int result = ft_isascii(test_value);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isascii(%d) = %d, expected %d\n", 
                RED, RESET, test_value, result, expected);
            failed_tests++;
        }
        else
        {
            printf("%s[OK]%s Testing boundary value %d\n", GREEN, RESET, test_value);
        }
        
        i++;
    }

    // Print summary
    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s           SUMMARY              %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n", MAGENTA, RESET);
    
    printf("Total tests: %d\n", total_tests);
    
    if (failed_tests == 0)
    {
        printf("%s✓ All tests passed!%s\n", GREEN, RESET);
    }
    else
    {
        printf("%s✗ Failed tests: %d%s\n", RED, failed_tests, RESET);
    }

    printf("%s=================================%s\n\n", MAGENTA, RESET);

    save_test_results("ft_isascii", total_tests, failed_tests);
}