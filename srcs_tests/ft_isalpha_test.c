/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:51:50 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/21 16:09:44 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_isalpha_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_isalpha tests        %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test uppercase letters
    printf("%sTesting uppercase letters (A-Z):%s\n", BLUE, RESET);
    for (int c = 'A'; c <= 'Z'; c++)
    {
        total_tests++;
        int expected = isalpha(c) ? 1 : 0;  // Convert to 1 or 0
        int result = ft_isalpha(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isalpha('%c') = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
    }

    // Test lowercase letters
    printf("\n%sTesting lowercase letters (a-z):%s\n", BLUE, RESET);
    for (int c = 'a'; c <= 'z'; c++)
    {
        total_tests++;
        int expected = isalpha(c) ? 1 : 0;
        int result = ft_isalpha(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isalpha('%c') = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
    }

    // Test numbers
    printf("\n%sTesting numbers (0-9):%s\n", BLUE, RESET);
    for (int c = '0'; c <= '9'; c++)
    {
        total_tests++;
        int expected = isalpha(c) ? 1 : 0;
        int result = ft_isalpha(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isalpha('%c') = %d, expected %d\n", 
                RED, RESET, c, result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, c);
    }

    // Test special characters
    printf("\n%sTesting special characters:%s\n", BLUE, RESET);
    char special[] = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>?/ ";
    for (int i = 0; special[i]; i++)
    {
        total_tests++;
        int expected = isalpha(special[i]) ? 1 : 0;
        int result = ft_isalpha(special[i]);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isalpha('%c') = %d, expected %d\n", 
                RED, RESET, special[i], result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing '%c'\n", GREEN, RESET, special[i]);
    }

    // Test extended ASCII values
    printf("\n%sTesting extended ASCII values (128-255):%s\n", BLUE, RESET);
    for (int c = 128; c < 256; c++)
    {
        total_tests++;
        int expected = isalpha(c) ? 1 : 0;
        int result = ft_isalpha(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isalpha(%d) = %d, expected %d\n", 
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
        int expected = isalpha(c) ? 1 : 0;
        int result = ft_isalpha(c);
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_isalpha(%d) = %d, expected %d\n", 
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

    save_test_results("ft_isalpha", total_tests, failed_tests);
}