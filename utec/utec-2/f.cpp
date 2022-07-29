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

ll n, m, T = 1, ans;
ll a, b;

bool good( int l ){
	while( l ){
		if( l % 10 != a and l % 10 != b ) return false;
		l /= 10;
	}
	return true;
}

ll INV[ N ];
ll F[ N ];
ll FI[ N ];

void prefac(ll Nmax, ll mod){
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

ll C( ll n, ll k, ll mod ){
  if( n < k ) return 0;
  return F[ n ] * FI[ k ] % mod * FI[ n - k ] % mod;
}

ll solve(){
	cin >> a >> b >> n;
	if( b > a ) swap(a, b);

	prefac(N, MOD7);

	FER( i , 1 , a * n + 1 ){
		if( !good( i ) ) continue;

		R( j , n + 1 ){
			if( j * a + ( n - j ) * b != i ) continue;
			ans += C( n , j, MOD7 );
			ans %= MOD7;
		}
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
