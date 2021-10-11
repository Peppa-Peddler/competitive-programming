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
#define all(x) x.begin(),x.end()
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

#define N N5

ll n, m, t = 1, ans;

string s[ 2*N3 ];

graph ro(30), co(30);

bool bends(){
	FER( c, 'a', 'z' + 1 ){
		ro[ c - 'a' ].clear();
		co[ c - 'a' ].clear();
		R(i, n)
			R(j, m)
			if( s[ i ][ j ] == c ){
				ro[ c - 'a' ].PB( i );
				break;
			}
		R(j, m)
			R(i, n)
			if( s[ i ][ j ] == c ){
				co[ c - 'a' ].PB( j );
				break;
			}
		if( len(co[ c - 'a' ]) > 1 and len(ro[ c - 'a' ]) > 1 )
			return true;
	}
	return false;
}

bool draw(char a, bool check = true ){
	if( a > 'z' ) return false;
	int r = len(ro[ a - 'a' ]), c = len(co[ a - 'a' ]), top, bot, row, col;
	if( r < 1 and c < 1 ) {
		if( check ) return true;
		return draw( a + 1, check );
	}
	ans = a - 'a' + 1;
	if( r > 1 ){
		col = co[ a - 'a' ][ 0 ];
		top = ro[ a - 'a' ][ 0 ];
		bot = ro[ a - 'a' ][ r - 1 ];
		if( !check ) cout << top + 1 << " " << col + 1 << " " << bot + 1 << " " << col + 1 << endl;
		FER( i, top + 1, bot ) if( s[ i ][ col ] < a ) return false;
	} else {
		row = ro[ a - 'a' ][ 0 ];
		top = co[ a - 'a' ][ 0 ];
		bot = co[ a - 'a' ][ c - 1 ];
		if( !check ) cout << row + 1 << " " << top + 1 << " " << row + 1 << " " << bot + 1 << endl;
		FER( j, top + 1, bot ) if( s[ row ][ j ] < a ) return false;
	}
	return true;
}

ll solve(){
	cin >> n >> m;

	ans = 0;
	R(i, n) cin >> s[ i ];
	R(i, n) R(j, m) if( s[ i ][ j ] == '.' ) s[ i ][ j ] = 'a' - 1;

	if( bends() ){
		cout << "NO" << endl;
		return 0;
	}

	FER( c, 'a', 'z' + 1 ){
		if( !draw(c) ) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	cout << ans << endl;
	FER( c, 'a', 'z' + 1 ) draw(c, false);

    return 0;
}

int main(){
	fastio;
    cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();
}
