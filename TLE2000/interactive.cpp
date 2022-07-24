#include<iostream>

using namespace std;

int main(){
	//int v[ 10 ] = { 7, 10, 3, 8, 9, 4, 5, 6, 1, 2 };
	int v[ 6 ] = { 2 , 1 , 6 , 3 , 5 , 4 };
	char s;
	int t, i , j , x;
	cin >> s >> t >> i >> j >> x;
	while( s == '?' ){
		if( t == 1 )
			cout << max(min(x, v[i - 1]), min(x + 1, v[j - 1])) << endl;
		if( t == 2 )
			cout << min(max(x, v[i - 1]), max(x + 1, v[j - 1])) << endl;
		cin >> s >> t >> i >> j >> x;
	}
}
