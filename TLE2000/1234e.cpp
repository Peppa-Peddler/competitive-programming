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

ll C[ N ];
ll BIT[ N+10 ][ 2 ];
ll v[ N ];

void upd(int x, bool b){
	for(; x <= N; x += x & -x) BIT[ x ][ b ] ++;
}

int qry(int x, bool b) {
	int sum = 0;
	for(; x > 0; x -= x & -x) sum += BIT[ x ][ b ];
	return sum;
}

ll solve(){

	n = nxt();
	m = nxt();

	R(i, m) {
		cin >> v[ i ];
	}

	ll DF, A, B, X;

	R(i, m - 1) {

		A = v[ i ];
		B = v[ i + 1 ];

		if( A == B ) continue;
		if( A > B ) swap( A , B );

		upd( A, 0 );
		upd( B, 1 );
		ans += B - A;
		C[ B ] += A - B + A + 1;

	}

	R(i, n){
		X = i + 1;
		cout << ans + C[ i + 1 ] - qry( i, 0 ) + qry( i , 1 ) + ( qry( i + 1, 0 ) - qry( i, 0 ) ) * i << " ";
	}

	cout << endl;

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
