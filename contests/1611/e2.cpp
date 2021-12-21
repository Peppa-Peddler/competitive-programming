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

#define N 2*N5

ll n, m, T = 1, ans;

graph G( N );
int D[ N ];
bool k[ N ];
int d[ N ];
bool vis[ N ];
vii v;

void dfs( int i, int dis, int dad ){
	if( vis[ i ] ) {
		ans++;
		return;
	}
	d[ i ] = dis;
	D[ i ] = dad;
	for( auto s: G[ i ] )
		if( s != dad )
			dfs( s, dis + 1, i );
}

ll solve(){
	n = nxt();
	m = nxt();

	v.clear();
	R(i, n){
		G[ i ].clear();
		k[ i ] = 0;
		vis[ i ] = 0;
	}

	R(i, m)
		k[ nxt() - 1 ] = 1;

	int a, b;

	R(i, n - 1){
		a = nxt() - 1;
		b = nxt() - 1;
		G[ a ].PB( b );
		G[ b ].PB( a );
	}

	dfs( 0, 0, 0 );

	int cur, dis;
	R(i, n)
		if( k[ i ] )
			v.EB( d[ i ], i );

	sort( all( v ) );

	R( i, len( v ) ){
		cur = v[ i ].S;
		dis = v[ i ].F;
		vis[ cur ] = true;
		R( j, dis / 2 ){
			cur = D[ cur ];
			if( vis[ cur ] ) break;
			vis[ cur ] = true;
		}
	}

	R(i, n){
		d[ i ] = -1;
	}

	ans = 0;
	dfs(0, 0, 0);

	R(i, n - 1){
		if( len(G[ i + 1 ]) != 1 ) continue;
		if( d[ i + 1 ] != -1 ){
			return -1;
		}
	}

	return ans;
}

int main(){
	fastio;
	T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
