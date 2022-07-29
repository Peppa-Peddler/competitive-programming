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

#define N N6

ll a, b, p, n, m, T = 1, ans;
vi cycle;
set< int > visited;

int INV[ N ];

void preinv(int mod){
	INV[ 1 ] = 1;
	for( ll i = 2; i < N ; i++ )
		INV[ i ] = mod - (ll)( mod / i ) * INV[ mod % i ] % mod;
}

ll solve(){
	cin >> a >> b >> p >> n;

	preinv( p );

	m = 1;
	while( !visited.count( m ) ){
		visited.insert( m );
		cycle.PB( m );
		m *= a;
		m %= p;
	}

	ll C = len( cycle ), l, r, Q, U;

	R(i, C){
		ll V = (p + b - cycle[ i ] * i % p) % p;
		V *= INV[ (C * cycle[ i ]) % p ];
		V %= p;

		l = 0, r = n / ( C * p ) + 1000;

		if( C * V + i > n ) continue;

		while( r - l > 1 ){
			ll mid = (r + l) / 2;
			if( C * p * mid + C * V + i > n )
				r = mid;
			else
				l = mid;
		}

		ll RR = l, LL = 0;

		if( C * V + i == 0 )
			LL ++;

		if( C * p * RR + C * V + i > n ) continue;
		ans += RR - LL + 1;
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
