/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_bzero_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_bzero tests          %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test cases for ft_bzero
    printf("%sTesting ft_bzero:%s\n", BLUE, RESET);
    
    // Test case 1: Zeroing a small buffer
    char buffer1[10] = "abcdefghij";
    char buffer1_std[10];
    memcpy(buffer1_std, buffer1, sizeof(buffer1)); // Copy original
    total_tests++;
    
    ft_bzero(buffer1, 5);
    bzero(buffer1_std, 5); // Use standard bzero for comparison
    
    if (memcmp(buffer1, buffer1_std, sizeof(buffer1)) != 0)
    {
        printf("%s[FAIL]%s ft_bzero(buffer1, 5) failed\n", RED, RESET);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing buffer1 with size 5 passed\n", GREEN, RESET);

    // Test case 2: Zeroing an entire buffer
    char buffer2[10] = "abcdefghij";
    char buffer2_std[10];
    memcpy(buffer2_std, buffer2, sizeof(buffer2)); // Copy original
    total_tests++;
    
    ft_bzero(buffer2, sizeof(buffer2));
    bzero(buffer2_std, sizeof(buffer2)); // Use standard bzero for comparison
    
    if (memcmp(buffer2, buffer2_std, sizeof(buffer2)) != 0)
    {
        printf("%s[FAIL]%s ft_bzero(buffer2, sizeof(buffer2)) failed\n", RED, RESET);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing buffer2 with full size passed\n", GREEN, RESET);

    // Test case 3: Zeroing zero bytes
    char buffer3[10] = "abcdefghij";
    char buffer3_std[10];
    memcpy(buffer3_std, buffer3, sizeof(buffer3)); // Copy original
    total_tests++;
    
    ft_bzero(buffer3, 0);
    
    if (memcmp(buffer3, buffer3_std, sizeof(buffer3)) != 0) // Should remain unchanged
    {
        printf("%s[FAIL]%s ft_bzero(buffer3, 0) failed\n", RED, RESET);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing buffer3 with size 0 passed\n", GREEN, RESET);

    // Test case 4: Zeroing a larger buffer
    char buffer4[20] = "0123456789abcdef";
    char buffer4_std[20];
    memcpy(buffer4_std, buffer4, sizeof(buffer4)); // Copy original
    total_tests++;
    
    ft_bzero(buffer4 + 5, 10); // Zeroing part of the buffer
    bzero(buffer4_std + 5, 10); // Use standard bzero for comparison
    
    if (memcmp(buffer4, buffer4_std, sizeof(buffer4)) != 0)
    {
        printf("%s[FAIL]%s ft_bzero(buffer4 + 5, 10) failed\n", RED, RESET);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing buffer4 with partial zeroing passed\n", GREEN, RESET);

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

     save_test_results("ft_bzero", total_tests, failed_tests);
}