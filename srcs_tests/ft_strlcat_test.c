/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

#include <bsd/string.h>
void ft_strlcat_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strlcat tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal concatenation
    printf("%sTesting normal concatenation:%s\n", BLUE, RESET);
    char dest1[20] = "Hello";
    char *src1 = " World!";
    
    size_t result1 = ft_strlcat(dest1, src1, sizeof(dest1)); // Should return 13
    char dest1_std[20];
    strcpy(dest1_std, "Hello");
    size_t result1_std = strlcat(dest1_std, src1, sizeof(dest1_std)); // Standard strlcat for comparison
    total_tests++;
    
    if (result1 != result1_std || strcmp(dest1, dest1_std) != 0)
    {
        printf("%s[FAIL]%s ft_strlcat(dest1, \"%s\", sizeof(dest1)) = %zu, expected %zu and \"%s\"\n", 
            RED, RESET, src1, result1, result1_std, dest1);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal concatenation passed\n", GREEN, RESET);

    // Test case 2: Destination buffer too small
    printf("\n%sTesting destination buffer too small:%s\n", BLUE, RESET);
    
    char dest2[10] = "Hello";
    
    size_t result2 = ft_strlcat(dest2, src1, sizeof(dest2)); // Should return 13
    char dest2_std[10];
    strcpy(dest2_std, "Hello");
    size_t result2_std = strlcat(dest2_std, src1, sizeof(dest2_std)); // Standard strlcat for comparison
    total_tests++;
    
    if (result2 != result2_std || strcmp(dest2, dest2_std) != 0) // Only "Hello" should remain
    {
        printf("%s[FAIL]%s ft_strlcat(dest2, \"%s\", sizeof(dest2)) = %zu, expected %zu and \"%s\"\n", 
            RED, RESET, src1, result2, result2_std, dest2);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing destination buffer too small passed\n", GREEN, RESET);

    // Test case 3: Zero length destination
    printf("\n%sTesting zero length destination:%s\n", BLUE, RESET);
   
	char dest3[0] = "";
    size_t result3 = ft_strlcat(dest3, src1, sizeof(dest3)); // Should return length of src since dest is empty
    size_t result3_std = strlcat(dest3, src1, sizeof(dest3)); // Standard strlcat for comparison
    total_tests++;
    
    if (result3 != result3_std)
    {
        printf("%s[FAIL]%s ft_strlcat(dest3, \"%s\", sizeof(dest3)) = %zu, expected %zu\n", 
            RED, RESET, src1, result3, result3_std);
        failed_tests++;
    }
    
     // Test case 4: Empty source string
     printf("\n%sTesting empty source string:%s\n", BLUE, RESET);
     
     char empty_src[] = "";
     char dest4[20] = "Hello";
     
     size_t result4 = ft_strlcat(dest4, empty_src, sizeof(dest4)); // Should return length of "Hello"
     size_t result4_std = strlcat(dest4, empty_src, sizeof(dest4)); // Standard strlcat for comparison
     total_tests++;
     
     if (result4 != result4_std)
     {
         printf("%s[FAIL]%s ft_strlcat(dest4, \"%s\", sizeof(dest4)) = %zu and \"%s\", expected %zu and \"%s\"\n", 
             RED, RESET, empty_src, result4, dest4, result4_std, "Hello");
         failed_tests++;
     }
     else
         printf("%s[OK]%s Testing empty source string passed\n", GREEN, RESET);

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

     save_test_results("ft_strlcat", total_tests, failed_tests);
}
