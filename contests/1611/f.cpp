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
ll v[ N ], s[ N ];

ll q( int l, int r ){
	ll L = 0, R = 0;
	if( l > 0 ) L = s[ l - 1 ];
	if( r >= 0 ) R = s[ r ];
	return R - L;
}

ll t[ 4 * N ];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = s[ tl ];
    } else {
        int tm = ( tl + tr ) / 2;
        build( v * 2, tl , tm );
        build( v * 2 + 1 , tm + 1 , tr );
        t[v] = min( t[ v * 2 ] , t[ v * 2 + 1 ] );
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return MOD9*1LL*MOD9;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sum(v*2, tl, tm, l, min(r, tm)),
			   sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

ll menor(int l, int r){
	return sum(1, 0, n - 1, l , r) + m - q( 0 , l - 1 );
}

ii bstry( int k ){
	R(i, n - k + 1)
		if( menor( i , i + k - 1 ) >= 0 )
			return {true, i};
	return {false, -1};
}

ll solve(){

	n = nxt();

	m = nxt();

	R(i, n)
		cin >> v[ i ];

	s[ 0 ] = v[ 0 ];

	R(i, n - 1)
		s[ i + 1 ] = s[ i ] + v[ i + 1 ];

	build(1, 0, n - 1);

	int l = 0, r = n + 1, mid;

	while( r - l > 1 ){
		mid = ( r + l ) / 2;
		if( bstry( mid ).F ) l = mid;
		else r = mid;
	}

	if( !l ){
		cout << -1 << endl;
	} else {
		int id = bstry( l ).S;
		cout << id + 1 << " " << id + l << endl;
	}

	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
