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

ll n, m, T = 1;

string s;

ll DP[ N ][ 4 ][ 4 ];

ll binpow( ll a, ll e ){
  ll ans = 1;
  while( e ){
    if( e & 1 ) ans = ans * a % MOD7;
    a = a * a % MOD7; e >>= 1;
  }
  return ans;
}

ll dp( int i, char c, int in ){

	if( c == 'c' ) return binpow( 3, m - in );

	if( i == n ) return 0;

	if( DP[ i ][ c - 'a' ][ in ] != -1 )
		return DP[ i ][ c - 'a' ][ in ];

	ll ans = dp( i + 1, c , in );

	if( s[ i ] == c + 1 )
		ans += dp( i + 1 , c + 1 , in );

	if( s[ i ] == '?' )
		ans += dp( i + 1 , c + 1 , in + 1 );

	return DP[ i ][ c - 'a' ][ in ] = ans % MOD7;

}

ll solve(){
	n = nxt();
	cin >> s;
	R(i, n) m += s[ i ] == '?';

	memset(DP, -1 , sizeof(DP));

	ll sum = 0;

	REF( i, n - 1 , 0 ){
		if( s[ i ] == 'a' )
			sum += dp( i + 1 , 'a' , 0 );
		if( s[ i ] == '?' )
			sum += dp( i + 1 , 'a' , 1 );
		sum %= MOD7;
	}

	return sum;
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
