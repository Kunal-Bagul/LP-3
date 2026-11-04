#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate maximum profit
int knapsack(vector<int>& wt, vector<int>& p, int n, int W,
             vector<vector<int>>& dp) {

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    p[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

// Function to display selected items
void displayItems(vector<int>& wt, vector<int>& p, int n, int W,
                  vector<vector<int>>& dp) {

    cout << "\nSelected Items:\n";

    for (int i = n; i > 0; i--) {

        if (dp[i][W] != dp[i - 1][W]) {

            cout << "Item " << i
                 << " Weight: " << wt[i - 1]
                 << " Profit: " << p[i - 1] << endl;

            W = W - wt[i - 1];
        }
    }
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), p(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter capacity: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    cout << "\nMaximum Profit: "<< knapsack(wt, p, n, W, dp) << endl;

    displayItems(wt, p, n, W, dp);

    return 0;
}
