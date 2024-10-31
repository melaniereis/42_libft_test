/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void ft_atoi_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_atoi tests            %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test valid positive integers
    printf("%sTesting valid positive integers:%s\n", BLUE, RESET);
    char *positive_tests[] = {
        "123",
        "  456",
        "\t789",
        "42abc",
        " +100",
        " +2147483647" // INT_MAX
    };
    
    size_t i = 0; // Use size_t for index variable
    while (i < sizeof(positive_tests) / sizeof(positive_tests[0]))
    {
        total_tests++;
        int result = ft_atoi(positive_tests[i]);
        int expected = atoi(positive_tests[i]); // Compare with standard atoi
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_atoi(\"%s\") = %d, expected %d\n", 
                RED, RESET, positive_tests[i], result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing \"%s\"\n", GREEN, RESET, positive_tests[i]);
        
        i++;
    }

    // Test valid negative integers
    printf("\n%sTesting valid negative integers:%s\n", BLUE, RESET);
    char *negative_tests[] = {
        "-123",
        " -456",
        "\t-789",
        "-42abc",
        " -100",
        " -2147483648" // INT_MIN
    };
    
    i = 0; // Reset index variable
    while (i < sizeof(negative_tests) / sizeof(negative_tests[0]))
    {
        total_tests++;
        int result = ft_atoi(negative_tests[i]);
        int expected = atoi(negative_tests[i]); // Compare with standard atoi
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_atoi(\"%s\") = %d, expected %d\n", 
                RED, RESET, negative_tests[i], result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing \"%s\"\n", GREEN, RESET, negative_tests[i]);
        
        i++;
    }

    // Test edge cases and invalid inputs
    printf("\n%sTesting edge cases and invalid inputs:%s\n", BLUE, RESET);
    char *edge_cases[] = {
        "abc123",
        "--123",
        "++123",
        "   ",
        "",
        NULL,
        "2147483648", // Overflow case
        "-2147483649" // Underflow case
    };
    
    i = 0; // Reset index variable
    while (i < sizeof(edge_cases) / sizeof(edge_cases[0]))
    {
        total_tests++;
        
        // Handle NULL case explicitly
        if (edge_cases[i] == NULL)
            break;

        int result = ft_atoi(edge_cases[i]);
        
        // For invalid inputs, we expect both to return 0
        int expected = atoi(edge_cases[i]); // Compare with standard atoi
        
        if (result != expected)
        {
            printf("%s[FAIL]%s ft_atoi(\"%s\") = %d, expected %d\n", 
                RED, RESET, edge_cases[i], result, expected);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing \"%s\"\n", GREEN, RESET, edge_cases[i]);
        
        i++;
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

    save_test_results("ft_atoi", total_tests, failed_tests);
}