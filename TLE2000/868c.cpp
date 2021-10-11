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

ll next(){ ll x; cin >> x; return x; }
ll n, m, t = 1, ans;

vi Q;

bool frec[ 20 ];

string solve(){

	n = next(), m = next();

	int v;

	R(i, 1 << 4) frec[ i ] = 0;
	R(i, n){
		v = 0;
		R(j, m) v |= next() << j;
		frec[ v ] = true;
	}

	Q.clear();
	R(i, 1 << m)
		if( frec[ i ] )
			Q.PB( i );

	int c[ 4 ];

	FER( mask , 1 , 1 << len(Q) ){

		R(i, m) c[ i ] = 0;
		R(i, len(Q))
			if( mask & ( 1 << i ) )
				R(j, m)
					if( Q[ i ] & ( 1 << j ) )
						c[ j ]++;

		bool flag = true;

		R(i, m)
			if( 2*c[ i ] > __builtin_popcount( mask ) ) flag = false;

		if( flag ) return "YES";

	}

	return "NO";

}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
