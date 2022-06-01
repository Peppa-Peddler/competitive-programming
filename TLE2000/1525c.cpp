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
typedef tuple<int, int> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N5

ll n, m, T = 1;

vi v;
vector< pair< ll, char > > pts[ 2 ];
map<ll, ll> ans;

void solution( bool id ){

	stack < ll > VL;
	queue < ll > VR;

	ll X, D, Xh, Dh;
	REF( i , len( pts[ id ] ) - 1 , 0 ){
		tie( X, D ) = pts[ id ][ i ];
		if( D == 'L' ){
			VL.push( X );
			continue;
		}
		if( !VL.empty() ){
			Xh = VL.top();
			VL.pop();
			ans[ Xh ] = (Xh - X)/2;
			ans[ X ] = (Xh - X)/2;
			continue;
		}
		VR.push( X );
	}

	ll L, Lh, R, Rh;

	L = R = 0;

	while( !VL.empty() ){
		L = VL.top();
		VL.pop();
		if( VL.empty() ) break;
		Lh = VL.top();
		VL.pop();
		ans[ Lh ] = ( Lh + L ) / 2;
		ans[ L ] = ( Lh + L ) / 2;
		L = 0;
	}

	while( !VR.empty() ){
		R = VR.front();
		VR.pop();
		if( VR.empty() ) break;
		Rh = VR.front();
		VR.pop();
		ans[ Rh ] = ( 2 * m - Rh - R ) / 2;
		ans[ R ] = ( 2 * m - Rh - R ) / 2;
		R = 0;
	}

	if( L and !R ){
		ans[ L ] = -1;
		return;
	}
	if( R and !L ){
		ans[ R ] = -1;
		return;
	}

	ans[ L ] = (L + m - R + m) / 2;
	ans[ R ] = (L + m - R + m) / 2;
}

ll solve(){

	cin >> n >> m;

	char d;

	v.clear();
	pts[ 0 ].clear();
	pts[ 1 ].clear();
	ans.clear();

	R(i, n)
		v.PB( nxt() );

	R(i, n){
		cin >> d;
		pts[ v[ i ]%2 ].EB( v[ i ] , d );
	}

	sort( all( pts[ 0 ] ) );
	sort( all( pts[ 1 ] ) );

	solution( 0 );
	solution( 1 );

	for( auto s: v )
		cout << ans[ s ] << " ";
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
