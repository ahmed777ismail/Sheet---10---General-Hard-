#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<long long>> matrix(n, vector<long long>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    vector<long long> res;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row from left to right
        for (int j = left; j <= right; ++j) {
            res.push_back(matrix[top][j]);
        }
        top++;
        if (top > bottom) break;

        // Traverse right column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            res.push_back(matrix[i][right]);
        }
        right--;
        if (left > right) break;

        // Traverse bottom row from right to left
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        if (top > bottom) break;

        // Traverse left column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    // Output the result
    for (size_t i = 0; i < res.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%lld", res[i]);
    }
    printf("\n");

    return 0;
}