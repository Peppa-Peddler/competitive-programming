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

#define N N5

ll p, n, m, T = 1, ans;

vi P;
vi primes;

int prime[ N ];

void criba(){
  for(int i = 0; i < N; i++) prime[ i ] = -1;
  for(int i = 4; i < N; i+=2) prime[ i ] = 2;
  for(ll i = 3; i*i < N; i+=2)
    if( prime[ i ] == -1 )
      for(ll j = i*i; j < N; j += 2*i)
        if( prime[ j ] == -1 )
          prime[ j ] = i;
  primes.PB(2);
  for(int i = 3; i < N; i+=2)
	  if( prime[ i ] == -1 )
		  primes.PB( i );
}

ll binpow( ll a, ll e , ll mod ){
	ll ans = 1;
	while( e ){
		if( e & 1 ) ans = ans * a % mod;
		a = a * a % mod; e >>= 1;
	}
	return ans;
}

bool is_primitive_root(int k){

	for(auto d: P)
		if( binpow( k , (p - 1) / d , p ) == 1 )
			return false;

	return true;
}

ll solve(){

	cin >> p >> n;

	if( p == 0 )
		return 0;

	P.clear();
	ll phi = p - 1;

	for( int i = 0; primes[ i ] * primes[ i ] <= p - 1 ; i++ ){
		if( phi % primes[ i ] ) continue;
		P.PB( primes[ i ] );
		while( phi % primes[ i ] == 0 )
			phi /= primes[ i ];
	}

	if( phi > 1 )
		P.PB( phi );

	R(i, n){
		m = nxt();
		cout << ( is_primitive_root( m ) ? "YES" : "NO" ) << endl;
	}

	return 1;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;

	criba();
	while( solve() );
	return 0;
}
