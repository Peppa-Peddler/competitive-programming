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

#define N 3*N5

ll n, m, T = 1;

int pre[ N ][ 27 ];
ll DP[ N ][ 27 ];
ll ans[ 27 ];

string s;

int q( int l, int r, int c ){
	int LL = 0, RR = pre[ r ][ c ];
	if( l ) LL = pre[ l - 1 ][ c ];
	return RR - LL;
}

int d( int l, int r ){
	int s = 0;
	R(i, 'z' - 'a' + 1){
		s += !!q( l, r, i );
	}
	return s;
}

ll solve(){

	cin >> s;

	n = len(s);

	int prev, l, r, mid;

	R(i, 'z' - 'a' + 1){
		prev = 0;
		R(j, n){
			prev += s[ j ] == (i + 'a');
			pre[ j ][ i ] = prev;
		}
	}

	int j, A = d( 0, n - 1 );

	R(i, n) DP[ i ][ 1 ] = i;

	FER(c , 1 , A + 1){
		j = DP[ 0 ][ c ];
		R(i, n){
			while( j < n && d(i, j) == c ) j++;
			DP[ i ][ c + 1 ] = j;
			ans[ c ] += j - DP[ i ][ c ];
		}
	}

	cout << A << endl;

	R(i, A){
		cout << ans[ i + 1 ] << endl;
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
