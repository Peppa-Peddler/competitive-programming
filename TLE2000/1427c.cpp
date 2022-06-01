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

#define N N5

ll n, m, T = 1;

int DP[ N ];
vii a;
vi t;

int abs( int x ){
	if( x < 0 ) return -x;
	else return x;
}

int dist( ii A, ii B ){
	return abs( A.F - B.F ) + abs( A.S - B.S );
}

int dp( int i ){
	if( i == len( a ) ) return 0;
	if( DP[ i ] != -1 ) return DP[ i ];
	int ans = 0;
	FER( j , i + 1 , min( len( a ) , i + 2010 ) ){
		if ( dist( a[ i ] , a[ j ] ) > t[ j ] - t[ i ] ) continue;
		ans = max( 1 + dp( j ) , ans );
	}
	return DP[ i ] = ans;
}

ll solve(){

	int r;

	cin >> r >> n;

	int x, y, z;

	a.EB( 1 , 1 );
	t.PB( 0 );

	R(i, n){
		cin >> z >> x >> y;
		a.EB( x , y );
		t.PB( z );
	}

	memset(DP, -1, sizeof(DP));

	REF( i , n , 0 )
		dp( i );

	return dp( 0 );
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
