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
typedef tuple<int, int, int> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N 2*N5

ll n, m, T = 1, root;

graph G (N);
vi p(N), d(N), acc(N);
vi ans(N);

ll solve(){

	n = nxt();

	R(i, n) G[ i ].clear();

	R(i, n){
		cin >> m;
		if( m - 1 != i )
			G[ m - 1 ].PB( i );
		else root = m - 1;
	}

	R(i, n){
		p[ i ] = nxt() - 1;
		d[ p[ i ] ] = i;
	}

	int D = 0, idx, cur, pd;

	PQ <Node> Q;

	Q.emplace( -d[ root ] , root, 0 );

	while(!Q.empty()){
		tie( idx , cur , pd ) = Q.top();
		Q.pop();
		if( D != -idx ){
			cout << -1 << endl;
			while(!Q.empty())
				Q.pop();
			return 0;
		}
		acc[ cur ] = D;
		ans[ cur ] = - pd + D++;
		for(auto v: G[ cur ])
			Q.emplace( -d[ v ] , v , acc[ cur ] );
	}

	R(i, n)
		cout << ans[ i ] << " ";

	cout << endl;

	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
