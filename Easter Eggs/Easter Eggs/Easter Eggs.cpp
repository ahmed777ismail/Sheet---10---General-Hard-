#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Base pattern of the 7 colors
    string base_colors = "ROYGBIV";
    string result;

    // For n > 7, we need to repeat part of the pattern while ensuring 4 consecutive eggs are different.
    if (n <= 7) {
        result = base_colors.substr(0, n);
    }
    else {
        // Add the base pattern first
        result = base_colors;

        // Repeat the last 4 colors (GBIV) to ensure no 4 consecutive eggs are the same
        string repeat_pattern = "GBIV";
        for (int i = 7; i < n; ++i) {
            result += repeat_pattern[(i - 7) % 4];
        }
    }

    // Output the result
    cout << result << endl;

    return 0;
}
