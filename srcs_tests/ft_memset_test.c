/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:02 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/31 10:08:05 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/31 14:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

// static int compare_memory(const void *s1, const void *s2, size_t n)
// {
//     const unsigned char *p1 = s1;
//     const unsigned char *p2 = s2;
//     size_t i = 0;
//
//     while (i < n)
//     {
//         if (p1[i] != p2[i])
//             return (0);
//         i++;
//     }
//     return (1);
// }

void ft_memset_test(void)
{
    // int failed_tests = 0;
    // int total_tests = 0;
    //
    // printf("\n%s=================================%s\n", MAGENTA, RESET);
    // printf("%s       ft_memset tests          %s\n", MAGENTA, RESET);
    // printf("%s=================================%s\n\n", MAGENTA, RESET);
    //
    // // Test case 1: Normal usage with char array
    // printf("%sTesting normal usage with char array:%s\n", BLUE, RESET);
    // char str1[15] = "Hello, World!";
    // char str1_std[15] = "Hello, World!";
    // int c1 = 'A';
    // size_t n1 = 5;
    // 
    // ft_memset(str1, c1, n1);
    // memset(str1_std, c1, n1);
    // total_tests++;
    // 
    // if (!compare_memory(str1, str1_std, sizeof(str1)))
    // {
    //     printf("%s[FAIL]%s ft_memset(str, %c, %zu) failed\n", RED, RESET, c1, n1);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing normal usage with char array passed\n", GREEN, RESET);
    //
    // // Test case 2: Set entire array
    // printf("\n%sTesting setting entire array:%s\n", BLUE, RESET);
    // int arr2[10] = {0};
    // int arr2_std[10] = {0};
    // int c2 = 0xFF;
    // size_t n2 = sizeof(arr2);
    // 
    // ft_memset(arr2, c2, n2);
    // memset(arr2_std, c2, n2);
    // total_tests++;
    // 
    // if (!compare_memory(arr2, arr2_std, n2))
    // {
    //     printf("%s[FAIL]%s ft_memset(arr, 0x%X, %zu) failed\n", RED, RESET, c2, n2);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing setting entire array passed\n", GREEN, RESET);
    //
    // // Test case 3: Set partial array
    // printf("\n%sTesting setting partial array:%s\n", BLUE, RESET);
    // char str3[20] = "Test partial set";
    // char str3_std[20] = "Test partial set";
    // int c3 = '_';
    // size_t n3 = 10;
    // 
    // ft_memset(str3, c3, n3);
    // memset(str3_std, c3, n3);
    // total_tests++;
    // 
    // if (!compare_memory(str3, str3_std, sizeof(str3)))
    // {
    //     printf("%s[FAIL]%s ft_memset(str, %c, %zu) failed\n", RED, RESET, c3, n3);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing setting partial array passed\n", GREEN, RESET);
    //
    // // Test case 4: Set with zero length
    // printf("\n%sTesting setting with zero length:%s\n", BLUE, RESET);
    // char str4[] = "Don't change me";
    // char str4_std[] = "Don't change me";
    // int c4 = 'X';
    // size_t n4 = 0;
    // 
    // ft_memset(str4, c4, n4);
    // memset(str4_std, c4, n4);
    // total_tests++;
    // 
    // if (!compare_memory(str4, str4_std, sizeof(str4)))
    // {
    //     printf("%s[FAIL]%s ft_memset(str, %c, %zu) failed\n", RED, RESET, c4, n4);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing setting with zero length passed\n", GREEN, RESET);
    //
    // // Test case 5: Set with non-char value
    // printf("\n%sTesting setting with non-char value:%s\n", BLUE, RESET);
    // unsigned char buf5[10];
    // unsigned char buf5_std[10];
    // int c5 = 0xAB;  // 171 in decimal
    // size_t n5 = sizeof(buf5);
    // 
    // ft_memset(buf5, c5, n5);
    // memset(buf5_std, c5, n5);
    // total_tests++;
    // 
    // if (!compare_memory(buf5, buf5_std, n5))
    // {
    //     printf("%s[FAIL]%s ft_memset(buf, 0x%X, %zu) failed\n", RED, RESET, c5, n5);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing setting with non-char value passed\n", GREEN, RESET);
    //
    // // Print summary
    // printf("\n%s=================================%s\n", MAGENTA, RESET);
    // printf("%s           SUMMARY              %s\n", MAGENTA, RESET);
    // printf("%s=================================%s\n", MAGENTA, RESET);
    // 
    // printf("Total tests: %d\n", total_tests);
    // 
    // if (failed_tests == 0)
    //     printf("%s✓ All tests passed!%s\n", GREEN, RESET);
    // else
    //     printf("%s✗ Failed tests: %d%s\n", RED, failed_tests, RESET);
    //
    // printf("%s=================================%s\n\n", MAGENTA, RESET);
    //
    // save_test_results("ft_memset", total_tests, failed_tests);
}
