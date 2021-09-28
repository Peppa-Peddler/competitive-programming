#include<bits/stdc++.h>
using namespace std;

#define Nmax 100

int n;
int BIT[ Nmax ];
int v[ Nmax ];

void upd(int x, int val = 1){
	for(; x <= n; x += x&-x) BIT[x] += val;
}

int qry(int x) {
	int sum = 0;
	for(; x > 0; x -= x&-x) sum += BIT[x];
	return sum;
}

int query(int l, int r){return qry( r ) - qry( l - 1 );}

void bit_clr(){
	for(int i = 0; i <= n; i++) BIT[ i ] = 0;
}

int main(){

	bit_clr();

	n = 8;
	int v[ 8 ] = { 10, 20, 30, 40, 50, 60, 70, 80 };

	for( int i = 0; i < 8 ; i++ ){
		upd( i + 1, v[ i ] );
		cout << v[ i ] << " ";
	} cout << endl;
	
	int a, b;
	while(true){
		cin >> a >> b;
		cout << query( a, b ) << endl;
	}
	
}
