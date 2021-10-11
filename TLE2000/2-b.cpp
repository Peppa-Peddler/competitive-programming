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

#define N N3

ll n, m, t = 1, ans;

ll DP[ N ][ N ][ 2 ];
ll v[ N ][ N ][ 2 ];
int zx = -1, zy;

ll dp( int i, int j, bool digit ){
	if( i >= n or j >= n ) return N6;
	ll u = v[ i ][ j ][ digit ];
	if( DP[ i ][ j ][ digit ] != -1 ) return DP[ i ][ j ][ digit ];
	if( i == n - 1 and j == n - 1 ) return u;
	return DP[ i ][ j ][ digit ] =
		u + min( dp( i + 1 , j, digit ) , dp ( i , j + 1, digit ) );
}

ll solve(){
	cin >> n;

	ll u, fv, tw;

	R(i, n)
		R(j, n){
		cin >> u;
		fv = tw = 0;
		DP[ i ][ j ][ 0 ] = DP[ i ][ j ][ 1 ] = -1;
		if( u == 0 ){
			fv = tw = 1;
			zx = i, zy = j;
		} else {
			while( u % 2 == 0 ) tw++, u/=2;
			while( u % 5 == 0 ) fv++, u/=5;
		}
		v[ i ][ j ][ 0 ] = tw;
		v[ i ][ j ][ 1 ] = fv;
	}

	FER( i, n - 1, 0 )
		FER( j, n - 1, 0 )
		dp(i, j, 0), dp(i, j, 1);

	ans = min( dp( 0, 0, 0), dp( 0, 0, 1) );

	if( zx > -1 and ans > 0 ){
		cout << 1 << endl;
		R(j, zy) cout << "R";
		R(i, zx) cout << "D";
		R(j, n - zy - 1) cout << "R";
		R(i, n - zx - 1) cout << "D";
		cout << endl;
		return 0;
	}

	cout << ans << endl;
	bool digit = 0;
	if( dp(0,0,0) > dp(0,0,1) ) digit = 1;

	int i = 0, j = 0;
	R(k, n + n - 2){
		if( dp(i + 1, j, digit) < dp(i, j + 1, digit) ){
			i++;
			cout << "D";
		} else {
			j++;
			cout << "R";
		}
	} cout << endl;

    return 0;
}

int main(){
	fastio;
    //cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();
}
