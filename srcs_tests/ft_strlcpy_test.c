/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

// Fallback implementation of strlcpy if it's not available
size_t my_strlcpy(char *dst, const char *src, size_t size) {
    size_t src_len = strlen(src);
    if (size == 0) return src_len;
    
    size_t copy_len = (src_len >= size) ? size - 1 : src_len;
    strncpy(dst, src, copy_len);
    dst[copy_len] = '\0'; // Ensure null termination
    return src_len;
}

void ft_strlcpy_test(void)
{
    // int failed_tests = 0;
    // int total_tests = 0;

    // printf("\n%s=================================%s\n", MAGENTA, RESET);
    // printf("%s       ft_strlcpy tests         %s\n", MAGENTA, RESET);
    // printf("%s=================================%s\n\n", MAGENTA, RESET);

    // // Test case 1: Normal copy
    // printf("%sTesting normal copy:%s\n", BLUE, RESET);
    // char src1[] = "Hello, World!";
    // char dest1[20];

    // size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1)); // Should return 13
    // size_t result1_std = my_strlcpy(dest1, src1, sizeof(dest1)); // Use fallback for comparison
    // total_tests++;
    // 
    // if (result1 != result1_std || strcmp(dest1, "Hello, World!") != 0)
    // {
    //     printf("%s[FAIL]%s ft_strlcpy(dest1, \"%s\", sizeof(dest1)) = %zu, expected %zu and \"%s\"\n", 
    //         RED, RESET, src1, result1, result1_std, dest1);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing normal copy passed\n", GREEN, RESET);

    // // Test case 2: Destination buffer too small
    // printf("\n%sTesting destination buffer too small:%s\n", BLUE, RESET);
    // 
    // char dest2[5];
    // 
    // size_t result2 = ft_strlcpy(dest2, src1, sizeof(dest2)); // Should return 13
    // size_t result2_std = my_strlcpy(dest2, src1, sizeof(dest2)); // Use fallback for comparison
    // total_tests++;
    // 
    // if (result2 != result2_std || strcmp(dest2, "Hell") != 0) // Only "Hell" should remain
    // {
    //     printf("%s[FAIL]%s ft_strlcpy(dest2, \"%s\", sizeof(dest2)) = %zu, expected %zu and \"%s\"\n", 
    //         RED, RESET, src1, result2, result2_std, dest2);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing destination buffer too small passed\n", GREEN, RESET);

    // // Test case 3: Zero length destination
    // printf("\n%sTesting zero length destination:%s\n", BLUE, RESET);
    // 
    // char dest3[20];
    // 
    // size_t result3 = ft_strlcpy(dest3, src1, 0); // Should return 13
    // total_tests++;
    // 
    // if (result3 != strlen(src1))
    // {
    //     printf("%s[FAIL]%s ft_strlcpy(dest3, \"%s\", 0) = %zu, expected %zu\n", 
    //         RED, RESET, src1, result3, strlen(src1));
    //     failed_tests++;
    // }
    // 
    //  // Test case 4: Empty source string
    //  printf("\n%sTesting empty source string:%s\n", BLUE, RESET);
    //  
    //  char empty_src[] = "";
    //  char dest4[20];
    //  
    //  size_t result4 = ft_strlcpy(dest4, empty_src, sizeof(dest4)); // Should return 0
    //  total_tests++;
    //  
    //  if (result4 != 0 || strcmp(dest4, "") != 0)
    //  {
    //      printf("%s[FAIL]%s ft_strlcpy(dest4, \"%s\", sizeof(dest4)) = %zu and \"%s\", expected %zu and \"\"\n", 
    //          RED, RESET, empty_src, result4, dest4);
    //      failed_tests++;
    //  }
    //  else
    //      printf("%s[OK]%s Testing empty source string passed\n", GREEN, RESET);

    //  // Print summary
    //  printf("\n%s=================================%s\n", MAGENTA, RESET);
    //  printf("%s           SUMMARY              %s\n", MAGENTA, RESET);
    //  printf("%s=================================%s\n", MAGENTA, RESET);
    //  
    //  printf("Total tests: %d\n", total_tests);
    //  
    //  if (failed_tests == 0)
    //      printf("%s✓ All tests passed!%s\n", GREEN, RESET);
    //  else
    //      printf("%s✗ Failed tests: %d%s\n", RED, failed_tests, RESET);

    //  printf("%s=================================%s\n\n", MAGENTA, RESET);

    //  save_test_results("ft_strlcpy", total_tests, failed_tests);
}
