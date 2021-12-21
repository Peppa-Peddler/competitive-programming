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

ll n, m, T = 1, ans;

string k;

bool DP[ 70 ][ 70 ];
bool C[ 70 ][ 70 ];

bool dp( int i, int cifra ){

	if( i >= len( k ) ) return !cifra;
	if( !cifra ) return false;

	if( k[ i ] == '0' )
		return dp( i + 1 , cifra - 1 );

	if( C[ i ][ cifra ] )
		return DP[ i ][ cifra ];

	C[ i ][ cifra ] = 1;
	ll num = 0;
	bool ans = false;
	FER( j , i , len( k ) ){
		num = 10LL * num + k[ j ] - '0';
		if( num >= n ) break;
		ans |= dp( j + 1 , cifra - 1 );
	}

	return DP[ i ][ cifra ] = ans;

}

ll solution(int i, int cifra){
	ll num = 0;
	bool ans;
	ll exp = 1;

	if( k[ i ] == '0' )
		return solution( i + 1, cifra - 1 );

	R(j, cifra - 1) exp *= n;
	FER( j , i , len( k ) ){
		num = 10LL * num + k[ j ] - '0';
		if( num >= n ) break;
		ans = dp( j + 1 , cifra - 1 );
		if( ans ){
			return exp*num + solution( j + 1, cifra - 1 );
		}

	}
	return 0;
}

ll solve(){
	n = nxt();
	cin >> k;

	FER( i , 1, len( k ) + 1 )
		if( dp( 0, i ) ){
			return solution( 0, i );
		}

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
