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

#define N7 10000007
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
typedef tuple<int, int> Node;

#define N N5

ll n, x, y, t = 1, ans;

ll DP[ N7 ];

ll dp( int k ){
	ll A, B, C;
	if( k >= n ) return ( k - n ) * x;
	if( DP[ k ] != -1 ) return DP[ k ];
	A = x + dp( k + 1 );
	B = y + dp( 2*k );
	if( k > 1 )
		C = y + x + dp( 2*k - 1 );
	else
		C = B + 1;
	return DP[ k ] = min( {A, B, C} );
}

ll solve(){
	cin >> n >> x >> y;
	R(i, n) DP[ i ] = -1;
	for( int i = n - 1; i > 0; i-- ) dp( i );
    return x + dp( 1 );
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
