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
typedef tuple<ll, ll, ll> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N5

ll n, m, T = 1, S;

edges G( N );
vector < Node > E;
ll leafs[ N ];

ll dfs( ll a = 0, ll dad = 0 ){

	if( a != 0 and len( G[ a ] ) == 1 ) return leafs[ a ] = 1;
	ll children = 0, b, w;

	for( auto s: G[ a ] ){
		tie( b , w ) = s;
		if( b == dad ) continue;
		children += dfs( b , a );
	}

	return leafs[ a ] = children;
}

ll solve(){

	cin >> n >> S;

	ll a, b, w, childs;

	R(i, n)
		G[ i ].clear();
	E.clear();

	R(i, n - 1){
		cin >> a >> b >> w;
		a-- , b--;
		E.EB( a , b , w );
		G[ a ].EB( b , w );
		G[ b ].EB( a , w );
	}

	dfs();

	PQ < Node > W;

	ll sum = 0;

	R(i, n - 1){
		tie( a , b , w ) = E[ i ];
		childs = min( leafs[ a ], leafs[ b ] );
		sum += w * childs;
		W.emplace( w * childs - ( w / 2 ) * childs , childs, w );
	}

	ll ans = 0;

   	while( sum > S ){
		ans ++;
		tie( a , childs , w ) = W.top();
		W.pop();
		sum -= a;
		w /= 2;
		W.emplace( w * childs - ( w / 2 ) * childs , childs , w );
	}

	return ans;
}

int main(){
	fastio;
	T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
