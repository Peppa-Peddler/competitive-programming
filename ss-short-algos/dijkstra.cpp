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
typedef tuple<int, int> Node;
typedef vector<vi> graph;
typedef vector<vii> edges;

#define N N5

ll n, m, t = 1, ans;
vi dist(N);
edges adj(N);

void dijkstra(int src){
	PQ< Node > Q;
	fill(all(dist), -1);
	Q.EP( 0, src );
	while(!Q.empty()){
		int v, d;
		tie(d, v) = Q.top(); Q.pop();
		if( dist[ v ] != -1 ) continue;
		dist[ v ] = -d;
		for( auto el: adj[ v ] ) Q.EP( d - el.S , el.F );
	}
}

ll solve(){
	cin >> n >> m;
	int a, b, d;
	R(i, m){
		cin >> a >> b >> d;
		adj[a].EB(b, d);
		adj[b].EB(a, d);
	}
	
	dijkstra(0);
	
		R(i, n)
		cout << dist[i] << " \n"[ i == n - 1 ];
	
  return 0;
}

int main(){
	fastio;
    //cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();
}
