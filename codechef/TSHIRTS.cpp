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

ll n, m, T = 1, ans;

int bit[ 101 ];
int DP[ 101 ][ 1 << 10 ];

int dp( int i , int mask ){

	if( i == 100 ) return mask == (1 << n) - 1;
	if( DP[ i ][ mask ] != -1 ) return DP[ i ][ mask ];
	ll c = dp( i + 1, mask );
	R(j, n){
		if( mask & ( 1 << j ) ) continue;
		if( bit[ i ] & ( 1 << j ) )
			c += dp( i + 1, mask | ( 1 << j ) );
		c %= MOD7;
	}
	return DP[ i ][ mask ] = c;
}

ll solve(){

	int p; char c;

	cin >> n;

	R(i, 100) bit[ i ] = 0;
	memset( DP, -1, sizeof(DP) );

	R(i, n) {
		do{
			scanf("%d%c", &p, &c);
			bit[ p - 1 ] |= ( 1 << i );
		} while( c != '\n' and c != EOF );
	}

	return dp(0, 0);
}

int main(){
	fastio;
	T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
