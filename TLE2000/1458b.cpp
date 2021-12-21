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
#define N2 102
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

#define N N2

ll n, m, T = 1, ans;

int a[ N ], b[ N ];

int DP[ N ][ N * N ][ 2 ];

ll solve(){

	n = nxt();

	int sT = 0;

	R(i, n){
		scanf("%d %d", &a[ i ], &b[ i ]);
		sT += b[ i ];
	}

	int left, right;

	R( i, N*N )
		R( j , N )
		DP[ j ][ i ][ 1 ] = DP[ j ][ i ][ 0 ] = -10000000;

	DP[ 0 ][ 0 ][ 1 ] = DP[ 0 ][ 0 ][ 0 ] = 0;

	REF( i , n - 1 , 0 ){
		FER( k , 1 , n + 1 ){
			FER( sum , 1 , N * N ){

				left = -10000000;
				if( a[ i ] <= sum )
					left = DP[ k - 1 ][ sum - a[ i ] ][ 1 - i % 2  ] + b[ i ];
				DP[ k ][ sum ][ i % 2 ] = max( left , DP[ k ][ sum ][ 1 - i % 2 ] );

			}
		}
	}

	double SSSS;

	R( k , n ){
		SSSS = 0;
		R( sum , N*N ){
			SSSS = max( SSSS , min( sum * 1.0 , sT*.5 + DP[ k + 1 ][ sum ][ 0 ]*.5 ) );
		}
		cout << SSSS << " ";
	}

	cout << endl;
	return 0;
}

int main(){
	//fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
