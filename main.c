#include <stdio.h>
#include <string.h>

#include "algorithms.h"

// Ham tien ich chay test.
void run_test(const char *test_name, const char *pattern, const char *text) {
    int m = strlen(pattern);
    int n = strlen(text);

    printf("Test: %s\n", test_name);
    printf("Text    (%d): '%s'\n", n, text);
    printf("Pattern (%d): '%s'\n", m, pattern);

    // Xu ly edge cases: pattern rong hoac pattern dai hon text.
    if (m == 0 || m > n) {
        printf("  -> Khong the match (Edge case)\n");
    } else {
        int matches = Not_So_Naive(pattern, m, text, n);
        if (matches == 0) {
            printf("  -> Khong tim thay match\n");
        }
    }

    printf("--------------------------------------------------\n");
}

int main() {


    // 1. Basic test.
    run_test("1. Basic Example", "GCAGAGAG", "GCATCGCAGAGAGTATACAGTACG");

    // 2. Pattern khong xuat hien.
    run_test("2. No match", "XYZ", "HELLO WORLD PROGRAMMING");

    // 3. Pattern xuat hien lien tiep va de len nhau.
    run_test("3. Overlapping match", "AA", "AAAAA");

    // 4. Pattern khop o dau text.
    run_test("4. Match at start", "ABC", "ABCDEFGHIJKLMNOP");

    // 5. Pattern khop o cuoi text.
    run_test("5. Match at end", "XYZ", "ABCDEFGHIJKLMNOPXYZ");

    // 6. Toan bo ky tu giong nhau.
    run_test("6. Same characters", "BBB", "BBBBBBBB");

    // 7. Edge case: pattern dai hon text.
    run_test("7. Pattern longer than text", "LONGERPATTERN", "SHORT");

    // 8. Chuoi co khoang trang va ky tu dac biet.
    run_test("8. Special characters", "x*y", "123 x*y 456 x*y!@#");

    return 0;
}
