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

ll n, k, t = 1, ans;

ll INV[ 5*N5 ];
ll F[ 5*N5 ];
ll FI[ 5*N5 ];

void prefac(int Nmax, int mod){
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

ll C( ll n, ll k, int mod ){
  if( n < k ) return 0;
  return F[ n ] * FI[ k ] % mod * FI[ n - k ] % mod;
}

ll solve(){
	cin >> n >> k;

	ll d;

	prefac(n + 1, MOD );

	ans = 0;
	FER(i, 1, n + 1){
		d = (n - i)/i;
		ans += C(d, k - 1, MOD);
		ans %= MOD;
	}

    return ans;
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
