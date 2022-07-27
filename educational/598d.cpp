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

#define N N3

ll n, m, T = 1;

string s[ N ];
int G[ N ][ N ];

vector <int> ans;

void dfs( int i, int j, int id ){
	G[ i ][ j ] = id;

	if( s[ i ][ j - 1 ] == '.' ){
		if( !G[ i ][ j - 1 ] )
			dfs( i , j - 1 , id );
	} else ans[ id ]++;

	if( s[ i - 1 ][ j ] == '.' ){
		if( !G[ i - 1 ][ j ] )
			dfs( i - 1 , j , id );
	} else ans[ id ]++;

	if( s[ i + 1 ][ j ] == '.' ){
		if( !G[ i + 1 ][ j ] )
			dfs( i + 1 , j , id );
	} else ans[ id ]++;

	if( s[ i ][ j + 1 ] == '.' ){
		if( !G[ i ][ j + 1 ] )
			dfs( i , j + 1 , id );
	} else ans[ id ]++;
}

ll solve(){
	n = nxt(); m = nxt();
	ll k = nxt();

	R(i, n)
		cin >> s[ i ];

	ll a, b;

	R(i, k){
		cin >> a >> b;
		a--, b--;
		ans.PB(-1);
		if( !G[ a ][ b ] ){
			ans.PB(0);
			dfs( a , b , len(ans) - 1 );
		}
		cout << ans[ G[ a ][ b ] ] << endl;
	}

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
