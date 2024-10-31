/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/30 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void ft_calloc_test(void)
{
    int failed_tests = 0;
    int total_tests = 0;

    printf("\n%s=================================%s\n", MAGENTA, RESET);
    printf("%s       ft_calloc tests          %s\n", MAGENTA, RESET);
    printf("%s=================================%s\n\n", MAGENTA, RESET);

    // Test case 1: Allocating memory for an array of integers
    printf("%sTesting allocation of an array of integers:%s\n", BLUE, RESET);
    size_t count1 = 5;
    size_t size1 = sizeof(int);
    
    int *arr1 = (int *)ft_calloc(count1, size1);
    int *arr1_std = (int *)calloc(count1, size1); // Standard calloc for comparison
    total_tests++;
    
    if (arr1 == NULL || arr1_std == NULL)
    {
        printf("%s[FAIL]%s ft_calloc(%zu, %zu) or calloc returned NULL\n", RED, RESET, count1, size1);
        failed_tests++;
    }
    else
    {
        // Compare contents
        if (memcmp(arr1, arr1_std, count1 * size1) != 0)
        {
            printf("%s[FAIL]%s ft_calloc(%zu, %zu) did not match calloc result\n", 
                RED, RESET, count1, size1);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing allocation of integers passed\n", GREEN, RESET);
        
        free(arr1); // Free allocated memory
        free(arr1_std); // Free allocated memory
    }

    // Test case 2: Allocating memory for an array of characters
    printf("\n%sTesting allocation of an array of characters:%s\n", BLUE, RESET);
    size_t count2 = 10;
    size_t size2 = sizeof(char);
    
    char *arr2 = (char *)ft_calloc(count2, size2);
    char *arr2_std = (char *)calloc(count2, size2); // Standard calloc for comparison
    total_tests++;
    
    if (arr2 == NULL || arr2_std == NULL)
    {
        printf("%s[FAIL]%s ft_calloc(%zu, %zu) or calloc returned NULL\n", RED, RESET, count2, size2);
        failed_tests++;
    }
    else
    {
        // Compare contents
        if (memcmp(arr2, arr2_std, count2 * size2) != 0)
        {
            printf("%s[FAIL]%s ft_calloc(%zu, %zu) did not match calloc result\n", 
                RED, RESET, count2, size2);
            failed_tests++;
        }
        else
            printf("%s[OK]%s Testing allocation of characters passed\n", GREEN, RESET);

        free(arr2); // Free allocated memory
        free(arr2_std); // Free allocated memory
    }

    // Test case 3: Allocating zero elements
    printf("\n%sTesting allocation with zero elements:%s\n", BLUE, RESET);
    
    void *arr3 = ft_calloc(0, sizeof(int));
    void *arr3_std = calloc(0, sizeof(int)); // Standard calloc for comparison
    total_tests++;

    if (arr3 != arr3_std) // Both should return NULL or a valid pointer
    {
        printf("%s[FAIL]%s ft_calloc(0, sizeof(int)) does not match calloc(0)\n", 
            RED, RESET);
        failed_tests++;
        
        if (arr3 != NULL) // Free allocated memory if it was allocated
            free(arr3);
        
        if (arr3_std != NULL) // Free allocated memory if it was allocated
            free(arr3_std);
        
        return; // Exit since we cannot compare further
    }

    printf("%s[OK]%s Testing allocation with zero elements passed\n", GREEN, RESET);

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

     save_test_results("ft_calloc", total_tests, failed_tests);
}