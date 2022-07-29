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

ll n, m, a, T = 1, ans;

int F[ N ];
vi K[ N ];

ll binpow( ll a, ll e ){
  ll ans = 1;
  a %= MOD;
  while( e ){
    if( e & 1 ) ans = ans * a % MOD;
    a = a * a % MOD; e >>= 1;
  }
  return ans;
}

ll solve(){
	n = nxt();

	R(i, n){
		m = nxt();
		R(j, m){
			a = nxt();
			F[ a ] ++;
			K[ i ].PB( a );
		}
	}

	R(i, n){
		R(j, len( K[ i ] )){
			ans += binpow( n * len( K[ i ] ) * n , MOD - 2 ) * F[ K[ i ][ j ] ] % MOD;
			ans %= MOD;
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
