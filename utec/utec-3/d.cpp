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

#define N 2*N5

ll n, m, T = 1, ans;
graph G( N );
ll grado[ N ];
ll C[ N ];
ll CCg[ N ];
ll CCs[ N ];

void dfs(int i, int CC){
	if( C[ i ] > -1 ) return;
	C[ i ] = CC;
	for( auto v: G[ i ] )
		if( C[ v ] == -1 )
			dfs( v , CC );
}

ll solve(){
	n = nxt(), m = nxt();
	int A, B;
	R(i, m){
		cin >> A >> B;
		A-- , B--;
		G[ A ].PB( B );
		G[ B ].PB( A );
		grado[ A ] ++;
		grado[ B ] ++;
	}
	memset( C, -1 , sizeof( C ) );
	R(i, n) if( C[ i ] == -1 ) dfs( i , i );
	R(i, n){
		CCs[ C[i] ] ++;
		CCg[ C[i] ] += grado[ i ];
		if( grado[ i ] != 2 )
			CCs[ C[ i ] ] = -2*N;
	}
	R(i, n)
		ans += ( CCs[ i ] >= 3 && CCg[ i ] == 2 * CCs[ i ] );
	return ans;
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
