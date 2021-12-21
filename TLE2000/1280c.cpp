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

ll n, m, T = 1, ans;

edges G( N );
int grado[ N ];
int nodes[ N ];
map < ii , bool > vis;
bool V[ N ];

ll solve(){

	int a, b, c;
	n = 2*nxt();

	vis.clear();
	R(i, n){
		grado[ i ] = V[ i ] = 0;
		nodes[ i ] = 1;
		G[ i ].clear();
	}

	R(i, n - 1){
		a = nxt() - 1;
		b = nxt() - 1;
		c = nxt();
		G[ a ].PB( {b, c} );
		G[ b ].PB( {a, c} );
		grado[ a ]++;
		grado[ b ]++;
	}

	queue < int > Q;

	R(i, n)
		if( grado[ i ] == 1 ){
			Q.push( i );
			V[ i ] = true;
		}

	ll I, D, cur;

	I = D = 0;

	ll s, d;
	while( !Q.empty() ){

		cur = Q.front();
		Q.pop();

		for( ii p: G[ cur ] ){

			tie( s, d ) = p;
			if( vis[ { min( cur, s ) , max( cur, s ) } ] ) continue;
			vis[ { min( cur, s ) , max( cur, s ) } ] = true;

			if( !V[ s ] ){
				grado[ s ]--;
				nodes[ s ] += nodes[ cur ];
			}

			if( grado[ s ] == 1 && !V[ s ] ){
				Q.push( s );
				V[ s ] = true;
			}

			I += d * min( (ll)nodes[ cur ], n - nodes[ cur ] );
			if( nodes[ cur ] % 2 )
				D += d;

			break;
		}
	}

	cout << D << " " << I << endl;
	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
