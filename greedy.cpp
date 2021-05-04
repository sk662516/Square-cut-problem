#include<bits/stdc++.h>
using namespace std;

int minimumSquare(int a, int b){
	long long Result = 0, Rem = 0;

	if (a < b)
	     swap(a, b);

	while (b > 0){
		Result += a/b;

		Rem = a % b;
		a = b;
		b = Rem;
	}

	return Result;
}

int main(){
	int n = 13, m = 11;
	cout << minimumSquare(n, m);
	return 0;
}
