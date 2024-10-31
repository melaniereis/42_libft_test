/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:23:28 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/22 11:47:12 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

typedef struct s_test_results {
    const char *test_name;
    int total_tests;
    int failed_tests;
} t_test_results;

#define MAX_TESTS 50
static t_test_results g_results[MAX_TESTS];
static int g_test_count = 0;

void save_test_results(const char *test_name, int total, int failed)
{
    if (g_test_count < MAX_TESTS)
    {
        g_results[g_test_count].test_name = test_name;
        g_results[g_test_count].total_tests = total;
        g_results[g_test_count].failed_tests = failed;
        g_test_count++;
    }
}

void print_final_summary(void)
{
    int total_tests = 0;
    int total_failed = 0;

    printf("\n%s==========================================%s\n", MAGENTA, RESET);
    printf("%s              FINAL SUMMARY              %s\n", MAGENTA, RESET);
    printf("%s==========================================%s\n\n", MAGENTA, RESET);

    for (int i = 0; i < g_test_count; i++)
    {
        total_tests += g_results[i].total_tests;
        total_failed += g_results[i].failed_tests;

        if (g_results[i].failed_tests == 0)
        {
            printf("%s✓%s %s: ", GREEN, RESET, g_results[i].test_name);
            printf("%sAll tests passed%s ", GREEN, RESET);
            printf("(%d/%d tests)\n", g_results[i].total_tests, g_results[i].total_tests);
        }
        else
        {
            printf("%s✗%s %s: ", RED, RESET, g_results[i].test_name);
            printf("%sFailed %d tests%s ", RED, g_results[i].failed_tests, RESET);
            printf("(%d/%d tests)\n", 
                g_results[i].total_tests - g_results[i].failed_tests, 
                g_results[i].total_tests);
        }
    }

    printf("\n%s-------------------------------------------%s\n", MAGENTA, RESET);
    
    if (total_failed == 0)
    {
        printf("%s✓ All functions passed!%s\n", GREEN, RESET);
    }
    else
    {
        printf("%s✗ Some tests failed%s\n", RED, RESET);
        printf("%sTotal failed tests: %d%s\n", RED, total_failed, RESET);
    }
    
    printf("%sTotal tests run: %d%s\n", BLUE, total_tests, RESET);
    printf("%s==========================================%s\n\n", MAGENTA, RESET);
}

int main(void)
{
    printf("%s\n╔══════════════════════════════════════╗%s", MAGENTA, RESET);
    printf("%s\n║          LIBFT BONUS TESTS           ║%s", MAGENTA, RESET);
    printf("%s\n╚══════════════════════════════════════╝%s\n", MAGENTA, RESET);

    // Initialize test counts for each function
    int total_tests = 1; // Assuming each test is one test
    int failed_tests = 0; // You will need to implement logic to determine failures

	// BONUS PART
	ft_lstnew_test();
	save_test_results("ft_lstnew", total_tests, failed_tests); // Update with actual counts
	ft_lstadd_front_test();
	save_test_results("ft_lstadd_front", total_tests, failed_tests); // Update with actual counts
	ft_lstsize_test();
	save_test_results("ft_lstsize", total_tests, failed_tests); // Update with actual counts
	ft_lstlast_test();
	save_test_results("ft_lstlast", total_tests, failed_tests); // Update with actual counts
	ft_lstadd_back_test();
	save_test_results("ft_lstadd_back", total_tests, failed_tests); // Update with actual counts
	ft_lstdelone_test();
	save_test_results("ft_lstdelone", total_tests, failed_tests); // Update with actual counts
	ft_lstclear_test();
	save_test_results("ft_lstclear", total_tests, failed_tests); // Update with actual counts
	ft_lstiter_test();
	save_test_results("ft_lstiter", total_tests, failed_tests); // Update with actual counts
	ft_lstmap_test();
	save_test_results("ft_lstmap", total_tests, failed_tests); // Update with actual counts

	// Print final summary of test results
	print_final_summary();

	return (0);
}