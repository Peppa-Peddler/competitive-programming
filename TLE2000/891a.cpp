#include<iostream>

using namespace std;

int v[ 2001 ];

int euclides(int a, int b){
	return b == 0 ? a : euclides( b, a % b );
}

int main(){

	int n;
	cin >> n;

	int s = 0;

	for(int i = 0; i < n; i++){
		cin >> v[ i ];
		s += v[ i ] == 1;
	}

	if( s ){
		cout << n - s << endl;
		return 0;
	}

	int L = n + 1, gcd;

	for(int i = 0; i < n; i++){
		gcd = v[ i ];
		for(int j = i + 1; j < n; j++){
			gcd = euclides( gcd, v[ j ] );
			if( gcd == 1 ){
				L = min( L, j - i + 1 );
				break;
			}

		}
	}

	if( L == n + 1 ) cout << -1 << endl;
	else cout << n + L - 2 << endl;
}
