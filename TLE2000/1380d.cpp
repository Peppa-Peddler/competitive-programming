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

#define N 2*N5

ll n, m, T = 1, ans;

vi a, b;

ll solve(){

	n = nxt();
	m = nxt();

	ll x, k, y, D, v;

	cin >> x >> k >> y;

	D = x - k * y;

	a.PB( -1 );

	R(i, n)
		a.PB( nxt() );

	R(i, m)
		b.PB( nxt() );

	a.PB( -1 );
	b.PB( -1 );

	int j = 1;
	ll prev = 0, mx, L , R, Mi, Ma;

	for( int i = 0; i < m + 1 ; i++ ){

		mx = 0;

		while( j < len(a) && a[ j ] != b[ i ] ) {
			mx = max( mx , a[ j ] );
			j++;
		}

		if( j == len( a ) )
			return -1;

		L = j - prev - 1;
		Mi = 0;
		Ma = L/k;


		if( mx > a[ prev ] and mx > a[ j ] ) Mi = 1;
		if( Ma < Mi ) return -1;

		if( D >= 0 ){
			ans += L * y + Mi * D;
		} else {
			ans += L * y + Ma * D;
		}

		prev = j++;
	}

	return ans;
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
