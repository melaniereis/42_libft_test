/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void ft_isdigit_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_isdigit tests        %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test digits
    printf("%sTesting digits (0-9):%s\n", BLUE, RESET);
    for (int c = '0'; c <= '9'; c++)
    {
        total_tests++;
        int expected = isdigit(c) ? 1 : 0;  // Expected outcome based on standard isdigit
        int result = ft_isdigit(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isdigit('%c') = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
    }

    // Test non-digit characters
    printf("\n%sTesting non-digit characters:%s\n", BLUE, RESET);
    char non_digits[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=[]{}\\|;:'\",.<>?/ ";
    for (int i = 0; non_digits[i]; i++)
    {
        total_tests++;
        int expected = isdigit(non_digits[i]) ? 1 : 0;  // Expected outcome based on standard isdigit
        int result = ft_isdigit(non_digits[i]);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isdigit('%c') = %d, expected %d\n", 
                RED, RESET, non_digits[i], result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, non_digits[i]);
    }

    // Test extended ASCII values
    printf("\n%sTesting extended ASCII values (128-255):%s\n", BLUE, RESET);
    for (int c = 128; c < 256; c++)
    {
        total_tests++;
        int expected = isdigit(c) ? 1 : 0;  // Expected outcome based on standard isdigit
        int result = ft_isdigit(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isdigit(%d) = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing value %d\n", GREEN, RESET, c);
    }

    // Test negative values
    printf("\n%sTesting negative values (-128 to -1):%s\n", BLUE, RESET);
    for (int c = -128; c < 0; c++)
    {
        total_tests++;
        int expected = isdigit(c) ? 1 : 0;  // Expected outcome based on standard isdigit
        int result = ft_isdigit(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isdigit(%d) = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing value %d\n", GREEN, RESET, c);
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

    save_test_results("ft_isdigit", total_tests, failed_tests);
}