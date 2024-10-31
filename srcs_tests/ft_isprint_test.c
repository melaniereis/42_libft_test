/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:57:06 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/17 15:59:16 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void ft_isprint_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_isprint tests        %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test all ASCII values (0 to 127)
    printf("%sTesting ASCII range (0 to 127):%s\n", BLUE, RESET);
    for (int c = 0; c <= 127; c++)
    {
        total_tests++;
        int expected = isprint(c) ? 1 : 0;  // Expected outcome based on standard isprint
        int result = ft_isprint(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isprint(%d) = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
        {
            if (expected) // Only print character if it's printable
                printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
            else
                printf("%s[OK]%s Testing value %d\n", GREEN, RESET, c);
        }
    }

    // Test extended ASCII values (128 to 255)
    printf("\n%sTesting extended ASCII values (128 to 255):%s\n", BLUE, RESET);
    for (int c = 128; c <= 255; c++)
    {
        total_tests++;
        int expected = isprint(c) ? 1 : 0;  // Expected outcome based on standard isprint
        int result = ft_isprint(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isprint(%d) = %d, expected %d\n", 
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
        int expected = isprint(c) ? 1 : 0;  // Expected outcome based on standard isprint
        int result = ft_isprint(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isprint(%d) = %d, expected %d\n", 
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

    save_test_results("ft_isprint", total_tests, failed_tests);
}