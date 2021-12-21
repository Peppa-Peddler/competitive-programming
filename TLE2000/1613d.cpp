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

#define N 5*N5

ll n, m, T = 1, ans;

ll a[ N ];
ll g[ N ];
ll k[ N ];

ll solve(){
	n = nxt();

	R(i, n)
		a[ i ] = nxt();

	R(i, n + 10)
		g[ i ] = k[ i ] = 0;

	ll u;

	g[ 0 ] = 1;

	R(i, n){
		u = a[ i ];
		g[ u + 1 ] *= 2;
		g[ u + 1 ] %= MOD;
		g[ u + 1 ] += g[ u ];
		g[ u + 1 ] %= MOD;

		k[ u + 1 ] *= 2;
		k[ u + 1 ] %= MOD;

		if( u ){
			k[ u - 1 ] *= 2;
			k[ u - 1 ] %= MOD;
			k[ u - 1 ] += g[ u - 1 ];
			k[ u - 1 ] %= MOD;
		}

	}

	ll ans = 0;

	R(i, n + 3){
		ans += k[ i ];
		ans %= MOD;
		ans += g[ i ];
		ans %= MOD;
	}

	return (ans - 1 + MOD)%MOD;
}

int main(){
 	fastio;
	T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
