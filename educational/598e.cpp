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

#define N N5

ll n, m, k, T = 1, ans;

ll DP[ 31 ][ 31 ][ 51 ];

ll dp( int n, int m, int k ){

	if( k == 0 ) return 0;
	if( k > n * m ) return INF;
	if( n * m == k ) return 0;

	if( DP[ n ][ m ][ k ] != -1 )
		return DP[ n ][ m ][ k ];
	ll ans = INF;
	for( int i = 0; i <= k; i++ ){
		for( int j = 1 ; j < n ; j++ )
			ans = min( ans , m * m + dp( n - j , m , i ) + dp( j , m , k - i ) );
		for( int j = 1 ; j < m ; j++ )
			ans = min( ans , n * n + dp( n , m - j , i ) + dp( n , j , k - i ) );
	}
	return DP[ n ][ m ][ k ] = ans;
}

ll solve(){
	cin >> n >> m >> k;
	return dp( n , m , k );
}

int main(){
	fastio;
	T = nxt();
	memset(DP, -1 , sizeof( DP ));
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
