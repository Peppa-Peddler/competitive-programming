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

ll n, m, t = 1, ans, c;

graph adj(N5);

int A[ N5 ], a[ N5 ];
int dad[ N5 ];

ll dfs(int i, int d = -1){
	ll com = a[ i ], tmp;
	dad[ i ] = d;
	for( auto it: adj[ i ] ) {
		if( it == d ) continue;
		tmp = dfs( it, i );
		com ^= tmp;
	}
	return A[ i ] = com;
}

string solve(){
	cin >> n >> m;
	int x, y;
	c = 0;
	ans = 0;
	
	R(i, n) adj[ i ].clear();
	R(i, n) {cin >> a[ i ]; ans ^= a[ i ];}
	
	R(i, n - 1){
		cin >> x >> y;
		x--, y--;
		adj[ x ].PB( y );
		adj[ y ].PB( x );
	}
	
	if( ans == 0 ) return "YES";

	int leaf = 0;
	
	R(i, n) if( len(adj[ i ]) == 1 ) leaf = i;
	
	dfs( leaf );
	
	bool flag = false;
	
	R(i, n)
		if( i != leaf and A[ i ] == ans ){
			R(j, n) A[ j ] = -1;
			flag = true;
			dfs( dad[ i ], i );
			break;
		}

	if( !flag ) return "NO";
	
	flag = false;
	R(i, n) flag |= A[ i ] == ans;
	
	if( m == 2 or !flag ) return "NO";
	return "YES";
}

int main(){
	fastio;
    cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
