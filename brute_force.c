#include "algorithms.h"
#include "utils.h"

int Brute_Force(const char *x, int m, const char *y, int n) {
    int i, j;
    int matches = 0;

    for (j = 0; j <= n - m; ++j) {
        /* Vòng for bên trong không có thân (dấu chấm phẩy ở cuối).
         * Nó chỉ tăng i miễn là i < m và ký tự x[i] khớp y[i + j].
         * Khi vòng kết thúc, i == m nếu toàn bộ m ký tự khớp,
         * hoặc i là chỉ số của ký tự đầu tiên không khớp.
         */
        for (i = 0; i < m && x[i] == y[i + j]; ++i)
            ; /* thân rỗng */

        /* Nếu i >= m thì tìm thấy một lần khớp bắt đầu tại vị trí j */
        if (i >= m) {
            OUTPUT(j);
            ++matches;
        }
    }

    return matches;
}
