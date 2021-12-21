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
typedef tuple<ll, ll, ll> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N5

ll n, m, T = 1, k;

ll D[ N ];
vector <Node> ans;

ll solve(){
	n = nxt();
	m = nxt();

	ll a , b , c;

	R(i , m){
		cin >> a >> b >> c;
		D[ a - 1 ] += c;
		D[ b - 1 ] -= c;
	}

	vi A, B;

	R(i, n){
		if( !D[ i ] ) continue;
		if( D[ i ] < 0 ) { A.PB( i ); D[ i ] *= -1;}
		else B.PB( i );
	}

	ll i , j, U, V;
	i = j = 0;

	while( i < len(A) and j < len(B) ){

		U = A[ i ];
		V = B[ j ];

		ans.EB(V + 1, U + 1, min( D[ U ], D[ V ] ));

		if( D[ U ] < D[ V ] )
			D[ V ] -= D[ U ], D[ U ] = 0, i++;
		else if( D[ U ] > D[ V ] )
			D[ U ] -= D[ V ], D[ V ] = 0, j++;
		else
			D[ U ] = D[ V ] = 0, i++, j++;
	}

	cout << len( ans ) << endl;
	for( auto P: ans ){
		tie( a , b , c ) = P;
		cout << a << " " << b << " " << c << endl;
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
