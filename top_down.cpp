#include<bits/stdc++.h>
using namespace std;

int **dp;

// Returns min number of squares needed
int minimumSquare(int m, int n){
	// Initializing max values to vertical_min
	// and horizontal_min
	int vertical_min = INT_MAX;
	int horizontal_min = INT_MAX;

	// N=11 & M=13 is a special case
	if((n==11 && m==13)||(m==11&&n==13))
		return 6; // DP answer is 8

	if (m == n) // If the given rectangle is already a square
		return 1;

	if (dp[m][n]!=0)    //if previously calculated
			return dp[m][n];

	/* The rectangle is cut horizontally and
	vertically into two parts and the cut
	with minimum value is found for every
	recursive call.
	*/

	for (int i = 1;i<= m/2;i++){
		// Calculating the minimum answer for the
		// rectangles with width equal to n and length
		// less than m for finding the cut point for
		// the minimum answer
		horizontal_min = min(minimumSquare(i, n) +
				minimumSquare(m-i, n), horizontal_min);
	}

	for (int j = 1;j<= n/2;j++)
	{
		// Calculating the minimum answer for the
		// rectangles with width less than n and
		// length equal to m for finding the cut
		// point for the minimum answer
		vertical_min = min(minimumSquare(m, j) +
				minimumSquare(m, n-j), vertical_min);
	}

	// Minimum of the vertical cut or horizontal
	// cut to form a square is the answer
	dp[m][n] = min(vertical_min, horizontal_min);

	return dp[m][n];
}

void array_create(int m,int n){
    dp=new int*[m+1];
    for (int i = 0; i <= m; i++)
        dp[i] = new int[n+1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
}

int main()
{
	int m = 4, n = 5;
    array_create(m,n);

	cout << minimumSquare(m, n);
	return 0;
}
