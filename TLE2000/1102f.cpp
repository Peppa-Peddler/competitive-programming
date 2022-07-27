#include<bits/stdc++.h>

#define EP emplace
#define EB emplace_back
#define PB push_back
#define PF push_front

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

int DP[ 2 << 16 ][ 16 ];
int v[ 16 ][ N ];

ll DL[ 16 ][ 16 ];
ll DC[ 16 ][ 16 ];

ll dl(int i, int j){
	ll ans = INF;
	R(k, m - 1){
		ans = min( ans, 0LL + abs( v[ i ][ k ] - v[ j ][ k + 1 ] ) );
	}
	return ans;
}

ll dc(int i, int j){
	ll ans = INF;
	R(k, m){
		ans = min( ans, 0LL + abs( v[ i ][ k ] - v[ j ][ k ] ) );
	}
	return ans;
}

ll dp( int mask, int first, int curr ){
	if( DP[ mask ][ curr ] != -1 ) return DP[ mask ][ curr ];
	if( mask + 1 == 1 << n )
		return DL[ first ][ curr ];
	ll ans = -1;
	for( int i = 0; i < n ; i++ ){
		if( (1 << i) & mask ) continue;
		ans = max( ans , 0LL + min( DC[ curr ][ i ], dp( mask | (1 << i) , first, i ) ) );
	}
	return DP[ mask ][ curr ] = ans;
}

ll solve(){

	cin >> n >> m;

	R(i, n)
		R(j, m)
		cin >> v[ i ][ j ];

	R(i, n)
		R(j, n){
		DL[ i ][ j ] = dl( i , j );
		DL[ j ][ i ] = dl( j , i );
		DC[ i ][ j ] = DC[ j ][ i ] = dc(i ,j);
	}

	ll ans = -1;

	R(i, n){
		memset( DP, -1, sizeof(DP) );
		ans = max( ans, dp( 1 << i, i, i ) );
	}

	return ans;
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
