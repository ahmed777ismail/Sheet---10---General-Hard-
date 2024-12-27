#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> weight(3, 0); // weight[0] for A, weight[1] for B, weight[2] for C
    string input;

    for (int i = 0; i < 3; ++i) {
        cin >> input;

        if (input[1] == '>') {
            // E.g., A > B means A is heavier
            weight[input[0] - 'A']++;
        }
        else {
            // E.g., A < B means B is heavier
            weight[input[2] - 'A']++;
        }
    }

    // Check for contradictions
    if (weight[0] == weight[1] || weight[1] == weight[2] || weight[0] == weight[2]) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Sort coins by weight
    string coins = "ABC";
    sort(coins.begin(), coins.end(), [&](char a, char b) {
        return weight[a - 'A'] < weight[b - 'A'];
        });

    cout << coins << endl;

    return 0;
}
