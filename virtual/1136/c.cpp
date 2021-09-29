#include<bits/stdc++.h>

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

#define fill(x, v) memset(x, v, sizeof(x))
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

#define N N5

ll n, m, t = 1, ans;

int a[ 502 ][ 502 ], b[ 502 ][ 502 ];
vi aa, bb;

string solve(){
	cin >> n >> m;

	R(i, n) R(j, m) cin >> a[ i ][ j ];
	R(i, n) R(j, m) cin >> b[ i ][ j ];

	
	
	for( ll i = 0; i < n ; i++ ){
		aa.clear();
		bb.clear();
		int j = 0;
		while( i - j >= 0 and j < m ){
			aa.PB( a[ i - j ][ j ] );
			bb.PB( b[ i - j ][ j ] );
			j++;
		}
		sort(all(aa));
		sort(all(bb));
		
		R(j, len(aa)){
			if( aa[ j ] != bb[ j ] ) return "NO";
		}
		
	}
	
	for( int i = 1; i < m ; i++ ){
		aa.clear();
		bb.clear();
		int j = 0;
		while( n - 1 - j >= 0 && i + j < m ){
			aa.PB( a[ n - 1 - j ][ i + j ] );
			bb.PB( b[ n - 1 - j ][ i + j ] );
			j++;
		}
		sort(all(aa));
		sort(all(bb));

		R(j, len(aa)){
			if( aa[ j ] != bb[ j ] ) return "NO";
		}
		
	}
	
    return "YES";
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
