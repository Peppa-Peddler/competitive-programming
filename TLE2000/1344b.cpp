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

string s[ N3 ];
bool vis[ N3 ][ N3 ];

bool overlap(){
	bool black;
	R(j, m){
		black = false;
		R(i, n - 1){
			if( s[ i ][ j ] == '#' ) black = true;
			if( s[ i ][ j ] == s[ i + 1 ][ j ] ) continue;
			if( s[ i + 1 ][ j ] == '#' and black ) return false;
		}
	}
	R(i, n){
		black = false;
		R(j, m - 1){
			if( s[ i ][ j ] == '#' ) black = true;
			if( s[ i ][ j ] == s[ i ][ j + 1 ] ) continue;
			if( s[ i ][ j + 1 ] == '#' and black ) return false;
		}
	}

	bool ver, hor;
	ver = hor = false;
	
	R(i, n){
		black = true;
		R(j, m) if( s[ i ][ j ] == '#' ) black = false;
		if( black ) ver = true;
	}

	R(j, m){
		black = true;
		R(i, n) if( s[ i ][ j ] == '#' ) black = false;
		if( black ) hor = true;
	}

	if( hor and !ver ) return false;
	if( ver and !hor ) return false;
	
	return true;
}

void dfs( int i, int j ){

	if( i < 0 or j < 0 ) return;
	if( i >= n or j >= m ) return;
	if( vis[ i ][ j ] ) return;
	
	vis[ i ][ j ] = true;
	
	if( s[ i ][ j ] != '#' ) return;
	
	dfs( i + 1 , j );
	dfs( i , j + 1 );
	dfs( i - 1 , j );
	dfs( i , j - 1 );
	
}

ll solve(){

	cin >> n >> m;

	R(i, n) cin >> s[ i ];
	
	if(!overlap()) return -1;
	
	R(i, n) R(j, m) vis[ i ][ j ] = false;

	R(i, n)
		R(j, m){
		if( vis[ i ][ j ] or s[ i ][ j ] != '#' ) continue;
		dfs(i, j);
		ans ++;
	}
	
    return ans;
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
