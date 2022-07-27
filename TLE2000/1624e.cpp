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
typedef tuple<int, int, int> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N3

ll n, m, T = 1, ans;

int DP[ N ];
string s;

map< string, Node > F;

bool dp(int i){
	if( i > m ) return false;
	if( i == m ) return true;
	if( i == m - 1 ) return false;
	if( DP[ i ] != -1 ) return DP[ i ];
	if( F.find( s.substr( i , 2 ) ) == F.end()  ) return false;
	ans = dp( i + 2 );
	if( i < m - 2 ){
		if( F.find( s.substr( i , 3 ) ) != F.end() )
			ans = ans || dp( i + 3 );
	}
	return DP[ i ] = ans;
}

ll solve(){

	F.clear();

	n = nxt();
	m = nxt();

	R(i, n){
		cin >> s;
		R(j, m - 1){
			F[ s.substr( j , 2 ) ] = { j + 1 , j + 2 , i + 1 };
			if( j + 2 < m )
				F[ s.substr( j , 3 ) ] = { j + 1 , j + 3 , i + 1 };
		}
	}

	cin >> s;

	memset( DP, -1, sizeof(DP) );

	if( !dp(0) ){
		cout << -1 << endl;
		return 0;
	}

	int i = 0;
	int R, L, I;
	vector < Node > ans;
	while( i < m - 1 ){
		if( dp( i + 2 ) ){
			ans.PB( F.find( s.substr( i , 2 ) ) -> second );
			i += 2;
		} else {
			ans.PB( F.find( s.substr( i , 3 ) ) -> second );
			i += 3;
		}
	}

	cout << len(ans) << endl;

	for( auto v: ans ){
		tie(R, L, I) = v;
		cout << R << " " << L << " " << I << endl;
	}

	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
