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

ll n, m, t = 1, ans;

vi vec;
ll frec[ 100 ];
vi primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int DP[ 75 ][ 524290 ];
ll v_mask[ 75 ];

ll binpow( ll a, ll e ){
  ll ans = 1;
  while( e ){
    if( e & 1 ) ans = ans * a % MOD7;
    a = a * a % MOD7; e >>= 1;
  }
  return ans;
}

ll dp( int i, ll mask ){
	if( i == len(vec) ) return mask == 0;
	if( DP[ i ][ mask ] != -1 ) return DP[ i ][ mask ];
	ll cur = v_mask[ i ], f = frec[ vec[ i ] ];
	ll SS = binpow( 2, f - 1 );
	ll right = SS * dp( i + 1 , mask );
	ll left  = SS * dp( i + 1 , mask ^ cur ) % MOD7;
	return DP[ i ][ mask ] = (right + left) % MOD7 ;
}

ll solve(){
	cin >> n;

	int u;

	R(i, n) {
		cin >> u;
		vec.PB( u );
		frec[ u ]++;
	}

	sort( all(vec) );
	vec.erase(unique(all(vec)), vec.end());

	R(i, len(vec)){
		ll cur = 0, u, v = vec[ i ], p, f = frec[ v ];
		for( int j = 0; j < len(primes); j++ ){
			u = 0, p = primes[ j ];
			while( v % p == 0 ) v /= p, u ^= 1;
			cur |= (u << j);
		}
		v_mask[ i ] = cur;
	}

	memset( DP, -1, sizeof(DP) );
    ans += (dp( 0, 0 ) - 1 + MOD7) % MOD7 ;
	return ans % MOD7;
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
