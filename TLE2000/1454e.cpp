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
int dad[ N ];
ll incycle[ N ];

ii cycle( int i = 0, int par = 0 ){
	if( dad[ i ] > -1 )
		return { par, i };
	ii node = {-1, -1};
	dad[ i ] = par;
	for( auto v: G[ i ] )
		if( v != par )
			node = max( node, cycle( v, i ) );
	return node;
}

void dfs( int i, int par, int root ){
	incycle[ root ]++;
	for( auto v: G[ i ] )
		if( v != par and incycle[ v ] == -1 )
			dfs( v, i, root );
}

ll solve(){
	n = nxt();

	int a, b;

	R(i, n) G[ i ].clear();
	R(i, n) dad[ i ] = -1;
	R(i, n) incycle[ i ] = -1;

	R(i, n){
		cin >> a >> b;
		a--, b--;
		G[ a ].PB( b );
		G[ b ].PB( a );
	}

	ll L, R;
	tie( L, R ) = cycle();
	incycle[ L ] = incycle[ R ] = 0;

	L = dad[ L ];

	while( incycle[ L ] == -1 ){
		incycle[ L ] = 0;
		L = dad[ L ];
	}

	ll ans = 0;

	R(i, n){
		if( incycle[ i ] == -1 ) continue;
		dfs( i , i , i );
		ans += incycle[ i ] * ( incycle[ i ] - 1 ) / 2;
		ans += incycle[ i ] * ( n - incycle[ i ] );
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
