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

#define N 5000

ll n, m, T = 1;

string A, B, C;
vi Z( N );

ii ZETA(string K, int L) {

	Z[ 0 ] = 0;
    for (int i = 1, l = 0, r = 0; i < len( K ); ++i) {
		Z[ i ] = 0;
        if (i <= r)
            Z[ i ] = min ( r - i + 1LL, Z[i - l] );
        while (i + Z[ i ] < len( K ) && K[ Z[ i ] ] == K[ i + Z[ i ] ])
            ++Z[ i ];
        if (i + Z[ i ] - 1 > r)
            l = i, r = i + Z[ i ] - 1;
    }

	ii ans = {0, 0};

	FER( i , L + 1, len( K ) )
		ans = max( ans , { Z[ i ], i - L } );

	return ans;
}

vii ans;

ll solve(){

	cin >> A;
	cin >> C;

	int L = len( A );

	B = A;
	reverse(all(B));

	A = C +'^'+ A;
	B = C +'^'+ B;

	int i = 0, k;
	ii D, I;

	while( i < len( C ) ){

		D = ZETA( A.substr( i ) , len( C ) - i );
		I = ZETA( B.substr( i ) , len( C ) - i );

		k = (max(D, I)).F;

		if( k == 0 ){
			cout << -1 << endl;
			return 0;
		}

		if( D > I )
			ans.EB( D.S, D.S + D.F - 1 );
		else
			ans.EB( L - I.S + 1, L - I.S + 1 - I.F + 1 );

		i += k;

	}

	cout << len(ans) << endl;

	for( auto s: ans ){
		cout << s.F << " " << s.S << endl;
	}

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//	while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
