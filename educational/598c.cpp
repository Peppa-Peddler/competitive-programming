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
typedef tuple< ll, ll, ll> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N N5

ll n, m, T = 1, ans;

int quarter( ii a ){
	ll x, y;
	tie(x, y) = a;
	if( y == 0 )
		return x > 0 ? 1 : 3;
	if( x == 0 )
		return y > 0 ? 2 : 4;
	if( y > 0 )
		return x > 0 ? 1 : 2;
	return x > 0 ? 4 : 3;
}

ll cross( ii a, ii b ){
	return a.F * b.S - a.S * b.F;
}

long double compare( pair < ii , int > a, pair < ii , int > b ){
	if( quarter( a.F ) != quarter( b.F ) )
		return quarter( a.F ) < quarter( b.F );
	return cross( a.F , b.F ) > 0;
}

long double module( ii a ){
	return sqrt( a.F * a.F + a.S * a.S );
}

ll solve(){
	n = nxt();

	int x, y;

	vector < pair< ii, ll > > P;

	R(i, n){
		cin >> x >> y;
		P.PB( { { x, y } , i + 1ll } );
	}

	sort(all(P), compare);

	P.PB( P[0] );

	pair < pair < long double, long double > , ii > ans;

	bool AD = false;

	ii axis[ 5 ] = { {0, 0} , {1, 0} , {0, 1} , {-1, 0} , {0, -1} };

	R(i, n){

		ii A = P[ i ].F;
		ii B = P[ i + 1 ].F;
		ll a = P[ i ].S;
		ll b = P[ i + 1 ].S;

		int Qa = quarter( A ), Qb = quarter( B );

		if( Qb == 1 and ( Qa != 4 and Qa != 1 ) )  continue;
		if( Qb - Qa > 1 ) continue;
		if( Qb - Qa < 0 and ( Qb != 1 or Qa != 4 ) ) continue;

		long double MA = module( A );
		long double MB = module( B );

		if( Qb != Qa and cross( axis[ Qa ], A ) * MB < cross( axis[ Qb ], B ) * MA )
			continue;

		long double C = cross( A , B ), M = MA * MB;

		if( C < 0 ) continue;

		if( !AD ){
			ans = { { C , M } , { a , b } };
			AD = true;
		} else if( ans.F.F * M > C * ans.F.S )
			ans = { { C , M } , { a , b } };

	}

	if( AD ){
		cout << ans.S.F << " " << ans.S.S << endl;
		return 0;
	}

	R(i, n){

		ii A = P[ i ].F;
		ii B = P[ i + 1 ].F;
		ll a = P[ i ].S;
		ll b = P[ i + 1 ].S;

		int Qa = quarter( A ), Qb = quarter( B );

		long double MA = module( A );
		long double MB = module( B );

		long double C = cross( A , B ), M = MA * MB;

		if( !AD ){
			ans = { { C , M } , { a , b } };
			AD = true;
		} else if( ans.F.F * M < C * ans.F.S )
			ans = { { C , M } , { a , b } };

	}

	cout << ans.S.F << " " << ans.S.S << endl;

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
