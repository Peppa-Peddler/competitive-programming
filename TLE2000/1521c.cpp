#include<bits/stdc++.h>

#define EP emplace
#define EB emplace_back
#define PB push_back
#define PF push_front
#define QTOP front
#define STOP top
#define PQTOP top

#define PQ priority_queue

#define MP make_pair
#define F first
#define S second

#define X first
#define Y second.first
#define Z second.second

#define MOD7 1000000007
#define MOD9 1000000009
#define MOD 998244353

#define N6 1000006
#define N5 100005
#define N4 10004
#define N3 1003
#define PI 3.1415926535897932384626
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define same(x) x.erase(unique(all(x)), x.end())
#define R(i, n) for(ll i = 0; i < ll(n) ; i++)

#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)
#define REF(i,a,b) for(ll i=ll(a); i>=ll(b); --i )

#define len(x) ((int)(x).size())
#define elif else if

#define sqr(x) 1LL * (x) * (x)
#define INF (ll) 1e15

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef vector<vii> edges;
typedef tuple<int, int> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N4

ll n, m, T = 1, ans;

int v[ N ];

int q( int t, int i, int j, int x ){
	int ans;
	cout << "? " << t << " " << i << " " << j << " " << x << endl;
	cin >> ans;
	return ans;
}

void show_ans(){
	cout << "! " << endl;
	R(i, n)
		cout << v[ i ] << " ";
	cout << endl;
}

void one_found(int i, int o = 1){

	v[ i - 1 ] = 1;
	FER( j , o - 1 , n ){
		if( j == i - 1 ) continue;
		v[ j ] = q( 1 , i , j + 1 , n - 1 );
	}
	return show_ans();

}

void two_found(int i, int o = 1){

	v[ i - 1 ] = 2;
	FER( j , o - 1 , n ){
		if( j == i - 1 ) continue;
		v[ j ] = q( 1 , i , j + 1 , n - 1 );
		if( v[ j ] == 2 )
			v[ j ] = 1;
	}
	return show_ans();

}

void val_found(int i, int val){

	v[ i - 1 ] = val;

	int BA, CB;
	int one = -1;

	for( int j = 4 ; j <= n - n%2 ; j += 2 ){

		BA = q( 2 , j , i , 1 );

		if( BA == 1 )
			return one_found( j , j );
		if( BA == 2 )
			return two_found( j , j );

		CB = q( 2 , j + 1 , j , 1 );

		if( CB == 1 )
			return one_found( j + 1 , j );
		if( CB == 2 )
			return two_found( j + 1 , j );

		if( BA == val ){
			if( CB < BA ){
				V[ j ] = ;
			}
		}


	}

	return show_ans();

}

void solve(){

	int A = 1, B = 2, C = 3;
	int AB, BA, BC, CB, AC, CA;

	AB = q( 2 , A , B , 1 );
	BA = q( 2 , B , A , 1 );

	BC = q( 2 , B , C , 1 );
	CB = q( 2 , C , B , 1 );

	AC = q( 2 , A , C , 1 );
	CA = q( 2 , C , A , 1 );

	if( AB == 1 )
		return one_found( 1 );
	if( BA == 1 )
		return one_found( 2 );
	if( CB == 1 )
		return one_found( 3 );

	if( AB == 2 and CA == 2 )
		return two_found( 1 );
	if( AB == 2 and BC == 2 )
		return two_found( 2 );
	if( BC == 2 and CA == 2 )
		return two_found( 3 );

	if( AB == CA )
		return val_found( 1 , AB );
	if( BC == BA )
		return val_found( 2 , BC );
	if( CA == CB )
		return val_found( 3 , CA );

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//	while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
