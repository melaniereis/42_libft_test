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

# include "../test.h"

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
    int tests_passed = 0;
    
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
            tests_passed++;
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
        printf("%s%d/%d functions passed all tests%s\n", 
            GREEN, tests_passed, g_test_count, RESET);
    }
    else
    {
        printf("%s✗ Some tests failed%s\n", RED, RESET);
        printf("%s%d/%d functions passed all tests%s\n", 
            YELLOW, tests_passed, g_test_count, RESET);
        printf("%sTotal failed tests: %d%s\n", RED, total_failed, RESET);
    }
    printf("%sTotal tests run: %d%s\n", BLUE, total_tests, RESET);
    printf("%s==========================================%s\n\n", MAGENTA, RESET);
}

int main(void)
{
    printf("%s\n╔══════════════════════════════════════╗%s", MAGENTA, RESET);
    printf("%s\n║          LIBFT FUNCTION TESTS        ║%s", MAGENTA, RESET);
    printf("%s\n╚══════════════════════════════════════╝%s\n", MAGENTA, RESET);
    
    // Initialize test counts for each function
    int total_tests = 0;
    int failed_tests = 0;

    // Part 1 - Character tests
    printf("\n%s=== Character Classification Tests ===%s\n", BLUE, RESET);
    ft_isalpha_test();
    save_test_results("ft_isalpha", total_tests, failed_tests);
    ft_isdigit_test();
    save_test_results("ft_isdigit", total_tests, failed_tests);
    ft_isalnum_test();
    save_test_results("ft_isalnum", total_tests, failed_tests);
    ft_isascii_test();
    save_test_results("ft_isascii", total_tests, failed_tests);
    ft_isprint_test();
    save_test_results("ft_isprint", total_tests, failed_tests);
    
    // Part 1 - String manipulation tests
    printf("\n%s=== String Manipulation Tests ===%s\n", BLUE, RESET);
    ft_strlen_test();
    save_test_results("ft_strlen", total_tests, failed_tests);
    ft_memset_test();
    save_test_results("ft_memset", total_tests, failed_tests);
    ft_bzero_test();
    save_test_results("ft_bzero", total_tests, failed_tests);
    ft_memcpy_test();
    save_test_results("ft_memcpy", total_tests, failed_tests);
    ft_memmove_test();
    save_test_results("ft_memmove", total_tests, failed_tests);
    ft_strlcpy_test();
    save_test_results("ft_strlcpy", total_tests, failed_tests);
    ft_strlcat_test();
    save_test_results("ft_strlcat", total_tests, failed_tests);
    
    // Part 1 - Character conversion tests
    printf("\n%s=== Character Conversion Tests ===%s\n", BLUE, RESET);
    ft_toupper_test();
    save_test_results("ft_toupper", total_tests, failed_tests);
    ft_tolower_test();
    save_test_results("ft_tolower", total_tests, failed_tests);
    
    // Part 1 - String search tests
    printf("\n%s=== String Search Tests ===%s\n", BLUE, RESET);
    ft_strchr_test();
    save_test_results("ft_strchr", total_tests, failed_tests);
    ft_strrchr_test();
    save_test_results("ft_strrchr", total_tests, failed_tests);
    ft_strncmp_test();
    save_test_results("ft_strncmp", total_tests, failed_tests);
    ft_memchr_test();
    save_test_results("ft_memchr", total_tests, failed_tests);
    ft_memcmp_test();
    save_test_results("ft_memcmp", total_tests, failed_tests);
    ft_strnstr_test();
    save_test_results("ft_strnstr", total_tests, failed_tests);
    
    // Part 1 - Memory allocation tests
    printf("\n%s=== Memory Allocation Tests ===%s\n", BLUE, RESET);
    ft_atoi_test();
    save_test_results("ft_atoi", total_tests, failed_tests);
    ft_calloc_test();
    save_test_results("ft_calloc", total_tests, failed_tests);
    ft_strdup_test();
    save_test_results("ft_strdup", total_tests, failed_tests);
    
    // Part 2 tests
    printf("\n%s=== Part 2 Function Tests ===%s\n", BLUE, RESET);
    ft_substr_test();
    save_test_results("ft_substr", total_tests, failed_tests);
    ft_strjoin_test();
    save_test_results("ft_strjoin", total_tests, failed_tests);
    ft_strtrim_test();
    save_test_results("ft_strtrim", total_tests, failed_tests);
    ft_split_test();
    save_test_results("ft_split", total_tests, failed_tests);
    ft_itoa_test();
    save_test_results("ft_itoa", total_tests, failed_tests);
    ft_strmapi_test();
    save_test_results("ft_strmapi", total_tests, failed_tests);
    ft_striteri_test();
    save_test_results("ft_striteri", total_tests, failed_tests);
    
    // File descriptor tests
    printf("\n%s=== File Descriptor Function Tests ===%s\n", BLUE, RESET);
    ft_putchar_fd_test();
    save_test_results("ft_putchar_fd", total_tests, failed_tests);
    ft_putstr_fd_test();
    save_test_results("ft_putstr_fd", total_tests, failed_tests);
    ft_putendl_fd_test();
    save_test_results("ft_putendl_fd", total_tests, failed_tests);
    ft_putnbr_fd_test();
    save_test_results("ft_putnbr_fd", total_tests, failed_tests);
    
    // Print final summary
    print_final_summary();
    
    return (0);
}
