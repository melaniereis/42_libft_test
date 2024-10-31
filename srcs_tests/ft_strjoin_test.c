/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_strjoin_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_strjoin tests         %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Normal string join
    printf("%sTesting normal string join:%s\n", BLUE, RESET);
    char *str1 = "Hello";
    char *str2 = " World!";
    
    char *result1 = ft_strjoin(str1, str2); // Should return "Hello World!"
    char *result1_std = malloc(strlen(str1) + strlen(str2) + 1); // Standard join for comparison
    if (result1_std)
        strcpy(result1_std, str1), strcat(result1_std, str2);
    
    total_tests++;
    
    if (strcmp(result1, result1_std) != 0)
    {
        printf("%s[FAIL]%s ft_strjoin(\"%s\", \"%s\") = \"%s\", expected \"%s\"\n", 
            RED, RESET, str1, str2, result1, result1_std);
        failed_tests++;
    }
    else
        printf("%s[OK]%s Testing normal string join passed\n", GREEN, RESET);
    
    free(result1); // Free allocated memory
    free(result1_std); // Free allocated memory

    // Test case 2: Joining with empty first string
    printf("\n%sTesting joining with empty first string:%s\n", BLUE, RESET);
    
    char *result2 = ft_strjoin("", str2); // Should return " World!"
    char *result2_std = strdup(str2); // Standard join for comparison
    total_tests++;
    
    if (strcmp(result2, result2_std) != 0)
    {
        printf("%s[FAIL]%s ft_strjoin(\"\", \"%s\") = \"%s\", expected \"%s\"\n", 
            RED, RESET, str2, result2, result2_std);
        failed_tests++;
    }
    
     free(result2); // Free allocated memory
     free(result2_std); // Free allocated memory

     // Test case 3: Joining with empty second string
     printf("\n%sTesting joining with empty second string:%s\n", BLUE, RESET);
     
     char *result3 = ft_strjoin(str1, ""); // Should return "Hello"
     char *result3_std = strdup(str1); // Standard join for comparison
     total_tests++;
     
     if (strcmp(result3, result3_std) != 0)
     {
         printf("%s[FAIL]%s ft_strjoin(\"%s\", \"\") = \"%s\", expected \"%s\"\n", 
             RED, RESET, str1, result3, result3_std);
         failed_tests++;
     }
     
     free(result3); // Free allocated memory
     free(result3_std); // Free allocated memory

     // Test case 4: Joining two empty strings
     printf("\n%sTesting joining two empty strings:%s\n", BLUE, RESET);
     
     char *result4 = ft_strjoin("", ""); // Should return ""
     char *result4_std = strdup(""); // Standard join for comparison
     total_tests++;
     
     if (strcmp(result4, result4_std) != 0)
     {
         printf("%s[FAIL]%s ft_strjoin(\"\", \"\") = \"%s\", expected \"%s\"\n", 
             RED, RESET, result4, result4_std);
         failed_tests++;
     }
     
     free(result4); // Free allocated memory
     free(result4_std); // Free allocated memory

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

     save_test_results("ft_strjoin", total_tests, failed_tests);
}