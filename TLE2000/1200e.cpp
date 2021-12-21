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

#define N N5

ll n, m, T = 1, ans;

vi Z( N6 );
string V[ N ], A, B;
vector< char > U, W;

void ZETA() {
	Z[ 0 ] = 0;
    for (int i = 1, l = 0, r = 0; i < len( W ); ++i) {
		Z[ i ] = 0;
        if (i <= r)
            Z[ i ] = min ( r - i + 1LL, Z[i - l] );
        while (i + Z[ i ] < len( W ) && W[ Z[ i ] ] == W[ i + Z[ i ] ])
            ++Z[ i ];
        if (i + Z[ i ] - 1 > r)
            l = i, r = i + Z[ i ] - 1;
    }
}

int overlap( int S ){
	int L = 0;
	REF( i , 2*S - 1 , S ){
		if( i + Z[ i ] == 2 * S )
			L = Z[ i ];
	}
	return L;
}

ll solve(){

	n = nxt();

	R(i, n) cin >> V[ i ];

	R(i, len( V[ 0 ] ))
		U.PB( V[ 0 ][ i ] );

	int S, O;

	FER( i , 1 , n ){
		S = min( len( U ) , len( V[ i ] ) );
		W.clear();
		R( j , S ) W.PB( V[ i ][ j ] );
		R( j , S ) W.PB( U[ j + len( U ) - S ] );

		ZETA();

		O = overlap( S );
		FER( j , O , len( V[ i ] ) )
			U.PB( V[ i ][ j ] );
	}

	for(char s: U)
		cout << s;
	cout << endl;

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
