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
#define MOD MOD7

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

ll n, k, m, T = 1, ans;

ll INV[ N ];
ll F[ N ];
ll FI[ N ];

ll binpow( ll a, ll e ){
  ll ans = 1;
  while( e ){
    if( e & 1 ) ans = ans * a % MOD7;
    a = a * a % MOD7; e >>= 1;
  }
  return ans;
}

void prefac(int Nmax, ll mod){
  INV[ 1 ] = 1;
  for( ll i = 2; i < Nmax ; i++ )
    INV[ i ] = mod - (ll)( mod / i ) * INV[ mod % i ] % mod;

  F[ 0 ] = 1;
  for( ll i = 1 ; i < Nmax ; i++ )
    F[ i ] = F[ i - 1 ]*i % mod;

  FI[ 0 ] = 1;
  for( ll i = 1 ; i < Nmax ; i++ )
    FI[ i ] = FI[ i - 1 ]*INV[ i ] % mod;
}

vi f;

ll PRE[ N ];
ll SUF[ N ];

ll POWERSUM(){

	ll LEN = len(f) - 1;

	if( n <= LEN )
		return f[ n ];

	PRE[ 0 ] = 1;

	FER(i, 1, LEN + 1)
		PRE[ i ] = ( n - i ) * PRE[ i - 1 ] % MOD7;

	SUF[ LEN + 1 ] = 1;

	REF(i, LEN , 1 )
		SUF[ i ] = ( n - i ) * SUF[ i + 1 ] % MOD7;

	ll V;

	FER(i, 1, LEN + 1){
		V = f[ i ] * PRE[ i - 1 ] % MOD7;
		V = V * SUF[ i + 1 ] % MOD7;
		V = V * FI[ LEN - i ] % MOD7;
		V = V * FI[ i - 1 ] % MOD7;
		V *= (LEN - i) % 2 ? -1 : 1;
		ans += V + MOD7;
		ans %= MOD7;
	}

	return ans;
}

ll solve(){
	prefac(N, MOD7);
	n = nxt(), k = nxt();
	ll PREV = 0;
	f.PB( 0 );
	R(i, k + 3){
		f.PB( ( PREV + binpow( i + 1 , k ) ) % MOD7  );
		PREV = f[ i + 1 ];
	}
	return POWERSUM();
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
