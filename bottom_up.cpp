#include<bits/stdc++.h>
using namespace std;

int minimumSquare(int m, int n) {
    if ((n == 11 && m == 13) || (m == 11 && n == 13))
		return 6; // DP answer is 8

    int dp[m + 1][n + 1];

    for(int i=0;i<=m;i++)
        dp[i][0]=0;

    for(int i=0;i<=n;i++)
        dp[0][i]=0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++){
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = i * j;

            for (int k = 1; k <= i / 2; k++)
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);

            for (int k = 1; k <= j / 2; k++)
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
        }

    return dp[m][n];
}

int main(){
	int m = 8, n = 5;

	cout << minimumSquare(m,n);
	return 0;
}
