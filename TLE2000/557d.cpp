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

ll n, m, t = 1, ans, two;

bool cycle;
int dis[ N5 ];

graph adj(N5);

ll bfs( int i ){
	int d, v;
	queue < Node > Q;
	Q.emplace( 0, i );
	ll odd = 0, eve = 0;
	while(!Q.empty()){
		tie(d, v) = Q.front();
		Q.pop();
		if( dis[ v ] != -1 ) continue;
		dis[ v ] = d;

		if( d == 1 ) two ++;

		if( d & 1 ) odd++;
		else eve ++;

		for( auto e: adj[ v ] ){
			Q.emplace( d + 1, e );
			if( dis[ e ] == d ) cycle = true;
		}
	}
	return (odd*(odd - 1) + eve*(eve - 1)) / 2;
}

ll solve(){
	int x, y;
	cin >> n >> m;
	R(i, n) dis[ i ] = -1;
	R(i, m){
		cin >> x >> y;
		x--, y--;
		adj[ x ].PB( y );
		adj[ y ].PB( x );
	}

	ans = two = cycle = 0;

	R(i, n){
		if( dis[ i ] != -1 ) continue;
		ans += bfs( i );
	}

	if( cycle ) {
		cout << "0 1" << endl;
		return 0;
	}

	if( ans ){
		cout << "1 " << ans << endl;
		return 0;
	}

	if( two ){
		cout << "2 " << two*( n - 2 ) << endl;
		return 0;
	}

	cout << "3 " << n*(n - 1)*(n - 2)/6 << endl;

    return 0;
}

int main(){
	fastio;
    //cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();
}
