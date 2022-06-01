#include <iostream>
#include <vector>

using namespace std;

#define N 10

int main(){

	int n, m;
	vector < int > adj[ N ]; // O( n^2 ) -> O( n + m )
	cin >> n >> m;
	for( int i = 0; i < m; i++ ){
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[ a ].push_back( b );
		adj[ b ].push_back( a );
	}
	int Q;
	cin >> Q;
	while( Q-- ){
		int q;
		cin >> q;
		cout << adj[ q - 1 ].size() << endl;
	}
}
