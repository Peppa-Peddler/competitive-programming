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

ll n, m, T = 1;

vector < Node > Q;
vi id;
vi Qs[ N ];
vi ans(N, -1);

int BIT[ N+500 ];

void upd(int x, int val, int n){
	for(; x <= n; x += x&-x) BIT[x] += val;
}

int qry(int x) {
	int sum = 0;
	for(; x > 0; x -= x&-x) sum += BIT[x];
	return sum;
}

void bit_clear(int n){
	for(int i = 0; i <= n; i++) BIT[ i ] = 0;
}

void process(int ID){
	vi Ts;
	ll a, b, c;

	for( auto P: Qs[ ID ] ){
		tie( a , b , c ) = Q[ P ];
		Ts.PB( b );
	}

	ll id;
	ll n = len( Ts ) + 10;

	sort(all(Ts));
	bit_clear( len( Ts ) + 10 );

	R( i, len( Qs[ ID ] ) ){
		tie( a , b , c ) = Q[ Qs[ ID ][ i ] ];
		id = lower_bound( all( Ts ) , b ) - Ts.begin() + 1;
		if( a == 1 )
			upd( id, +1 , n );
		else if( a == 2 )
			upd( id, -1 , n );
		else
			ans[ Qs[ ID ][ i ] ] = qry( id );
	}

};

ll solve(){
	n = nxt();
	int a, b, c;

	R(i, n){
		cin >> a >> b >> c;
		Q.EB( a , b , c );
		id.PB( c );
	}

	sort( all( id ) );
	same( id );

	ll ID;

	R( i, len( Q ) ){
		tie( a , b , c ) = Q[ i ];
		ID = lower_bound( all( id ) , c ) - id.begin();
		Qs[ ID ].PB( i );
	}

	R( i, len( id ) )
		process( i );

	for( auto s: ans ){
		if( s == -1 ) continue;
		cout << s << endl;
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
