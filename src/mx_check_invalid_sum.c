#include "pathfinder.h"

void mx_check_invalid_sum(int** matrix, int n) {
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j];

            if (sum > MAX_INT) {
                mx_error_handler(INVALID_BRIDGES_SUM, NULL);
            }
        }
    }
}

