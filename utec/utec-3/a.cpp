#include<bits/stdc++.h>

#define EP emplace
#define EB emplace_back
#define PB push_back
#define PF push_front

#define PQ priority_queue

#define MP make_pair
#define F first
#define S second

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

#define N 505

ll n, m, T = 1, ans;

string s[ N ];
int D[ N ][ N ];

int BFS(){
	queue < Node > Q;
	int X, Y, d, K;
	Q.emplace( 0, 0, 0 );
	while(!Q.empty()){

		tie(X, Y, d) = Q.front();
		Q.pop();

		if( D[ X ][ Y ] != -1 ) continue;
		D[ X ][ Y ] = d;

		K = s[ X ][ Y ] - '0';

		if( X + K < n && D[ X + K ][ Y ] == -1 )
			Q.emplace( X + K, Y, d + 1 );

		if( X - K >= 0 && D[ X - K ][ Y ] == -1 )
			Q.emplace( X - K, Y, d + 1 );

		if( Y + K < m && D[ X ][ Y + K ] == -1 )
			Q.emplace( X , Y + K, d + 1 );

		if( Y - K >= 0 && D[ X ][ Y - K ] == -1 )
			Q.emplace( X , Y - K, d + 1 );

	}
	return D[ n - 1 ][ m - 1 ];
}

ll solve(){
	memset(D, -1, sizeof(D));
	n = nxt(), m = nxt();
	R(i, n) cin >> s[ i ];
	return BFS();
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
