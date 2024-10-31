/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_substr_test(void)
{
    // int failed_tests = 0;
    // int total_tests = 0;
    //
    // printf("\n%s=================================%s\n", MAGENTA, RESET);
    // printf("%s       ft_substr tests          %s\n", MAGENTA, RESET);
    // printf("%s=================================%s\n\n", MAGENTA, RESET);
    //
    // // Test case 1: Normal substring extraction
    // printf("%sTesting normal substring extraction:%s\n", BLUE, RESET);
    // char *str1 = "Hello, World!";
    // 
    // char *result1 = ft_substr(str1, 7, 5); // Should return "World"
    // char *expected_result1 = malloc(6); // +1 for null terminator
    // if (expected_result1) {
    //     strncpy(expected_result1, str1 + 7, 5);
    //     expected_result1[5] = '\0'; // Null terminate
    // }
    // total_tests++;
    // 
    // if (strcmp(result1, expected_result1) != 0)
    // {
    //     printf("%s[FAIL]%s ft_substr(\"%s\", 7, 5) = \"%s\", expected \"%s\"\n", 
    //         RED, RESET, str1, result1 ? result1 : "NULL", expected_result1 ? expected_result1 : "NULL");
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing normal substring extraction passed\n", GREEN, RESET);
    // 
    // free(result1); // Free allocated memory
    // free(expected_result1); // Free allocated memory
    //
    // // Test case 2: Start index out of bounds
    // printf("\n%sTesting start index out of bounds:%s\n", BLUE, RESET);
    // 
    // char *result2 = ft_substr(str1, 20, 5); // Should return ""
    // total_tests++;
    // 
    // if (strcmp(result2, "") != 0)
    // {
    //     printf("%s[FAIL]%s ft_substr(\"%s\", 20, 5) = \"%s\", expected \"\"\n", 
    //         RED, RESET, str1, result2);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing out of bounds passed\n", GREEN, RESET);
    // 
    // free(result2); // Free allocated memory
    //
    // // Test case 3: Length exceeds string length
    // printf("\n%sTesting length exceeds string length:%s\n", BLUE, RESET);
    // 
    // char *result3 = ft_substr(str1, 0, 50); // Should return "Hello, World!"
    // char *expected_result3 = malloc(strlen(str1) + 1); // +1 for null terminator
    // if (expected_result3) {
    //     strcpy(expected_result3, str1);
    // }
    // 
    // total_tests++;
    // 
    // if (strcmp(result3, expected_result3) != 0)
    // {
    //     printf("%s[FAIL]%s ft_substr(\"%s\", 0, 50) = \"%s\", expected \"%s\"\n", 
    //         RED, RESET, str1, result3 ? result3 : "NULL", expected_result3 ? expected_result3 : "NULL");
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing length exceeds passed\n", GREEN, RESET);
    // 
    // free(result3); // Free allocated memory
    // free(expected_result3); // Free allocated memory
    //
    // // Test case 4: Zero length extraction
    // printf("\n%sTesting zero length extraction:%s\n", BLUE, RESET);
    // 
    // char *result4 = ft_substr(str1, 0, 0); // Should return ""
    // total_tests++;
    // 
    // if (strcmp(result4, "") != 0)
    // {
    //     printf("%s[FAIL]%s ft_substr(\"%s\", 0, 0) = \"%s\", expected \"\"\n", 
    //         RED, RESET, str1, result4);
    //     failed_tests++;
    // }
    // else
    //     printf("%s[OK]%s Testing zero length passed\n", GREEN, RESET);
    // 
    // free(result4); // Free allocated memory
    //
    //  // Test case 5: Null string input
    //  printf("\n%sTesting null string input:%s\n", BLUE, RESET);
    //  
    //  char *result5 = ft_substr(NULL, set2); // Should return NULL
    //  total_tests++;
    //  
    //  if (result5 != NULL)
    //  {
    //      printf("%s[FAIL]%s ft_substr(NULL) should return NULL but got a non-NULL pointer.\n", 
    //          RED, RESET);
    //      failed_tests++;
    //  }
    //  else
    //      printf("%s[OK]%s Testing null input passed\n", GREEN, RESET);
    //
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
    //
    //  printf("%s=================================%s\n\n", MAGENTA, RESET);
    //
    //  save_test_results("ft_strtrim", total_tests, failed_tests);
}
