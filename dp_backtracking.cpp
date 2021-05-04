// (a) add DP upper bound
// (b) use backtracking and pass array by reference to be memory efficient
// (c) other minor changes such as removing redundant variables & rewriting conditions
// (d) does not include the skyline record since it does not reduce time complexity significantly in tests
// Time Complexity: O(m^n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

void dfs(const int& n, const int& m, int heights[], int cnt, int& res){
    if (cnt >= res) return;

    int left(0), min_height(m);
    for (int i = 0; i < n; i++)
        if (heights[i] < min_height)
            min_height = heights[left = i];

    if (min_height == m){
        res = min(cnt, res);
        return;
    }

    int right(left);
    while (right < n && heights[left] == heights[right] && right - left + min_height < m)
        right++;

    for (int i = left; i < right; i++)
        heights[i] += right - left;

    for (int size = right - left; size >= 1; size--){
        dfs(n, m, heights, cnt + 1, res);

        // update the rectangle to contain the next smaller square
        for (int i = left; i < left + size - 1; i++)
            heights[i]--;
        heights[left + size - 1] -= size;
    }
}


int minimumSquare(int n, int m){
    if (n == m) return 1;
    if (n > m) swap(n, m);
    int heights[n] = {};

    int dp[n + 1][m + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (i == j){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = i * j;

            for (int k = 1; k <= i / 2; k++)
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);

            for (int k = 1; k <= j / 2; k++)
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
        }

    int res(dp[n][m]);
    dfs(n, m, heights, 0, res);
    return res;
}

int main(){
    int m = 11, n = 13;

    cout << minimumSquare(m,n);
    return 0;
}
