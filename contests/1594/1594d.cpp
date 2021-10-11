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
#define all(x) x.begin(),x.end()
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
typedef tuple<int, int, string> Node;

#define N 2*N5

ll n, m, t = 1, ans;

int vis[ N ][ 2 ];

graph sus( N );
graph crew( N );
set <Node> S;

ll dfs( int i, bool tr ){
	if( vis[ i ][ !tr ] == 1 ) return -N - 100;
	if( vis[ i ][ tr ] ) return 0;
	vis[ i ][ tr ] = 1;

	ll sum = !tr;

	for( auto it: sus[ i ] )
		sum += dfs( it, !tr );
	for( auto it: crew[ i ] )
		sum += dfs( it, tr );
	vis[ i ][ tr ] = 2;
	return sum;
}

ll solve(){
	cin >> n >> m;

	int x, y;
	string c;

	R(i, n){
		sus[ i ].clear();
		crew[ i ].clear();
		vis[ i ][ 0 ] = vis[ i ][ 1 ] = 0;
	}

	S.clear();

	R(i, m){
		cin >> x >> y >> c;
		x --, y--;
		S.EP(x, y, c);
	}

	for(auto v: S) {
		tie(x, y, c) = v;
		if( c == "imposter" ){
			sus[ x ].PB( y );
			sus[ y ].PB( x );
		} else {
			crew[ x ].PB( y );
			crew[ y ].PB( x );
		}
	}

	ans = 0;

	ll r, l, val;

	for( int i = 0; i < n; i++ ){
		if( !vis[ i ][ 1 ] and !vis[ i ][ 0 ] ){
			r = dfs( i, true );
			l = dfs( i, false );
			if( r < 0 or l < 0 ) return -1;
			ans += max( r, l );
		}
	}

    return ans;
}

int main(){
	fastio;
    cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
