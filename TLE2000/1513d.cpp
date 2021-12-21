
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

ii t[ 4 * N ];
ll a[ N ];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = { a[ tl ] , tl };
    } else {
        int tm = ( tl + tr ) / 2;
        build( v * 2, tl , tm );
        build( v * 2 + 1 , tm + 1 , tr );
        t[v] = min( t[ v * 2 ] , t[ v * 2 + 1 ] );
    }
}

ii sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {INF, -1};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sum(v*2, tl, tm, l, min(r, tm)),
			   sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int menor(int l, int r){
	return sum(1, 0, n - 1, l , r).S;
}

ll merge(int l, int r){

	if( r <= l ) return 0;

	int i , j;
	j = i = menor(l , r);
	j --;

	ll ans = 0;

	while( j >= l and __gcd( a[ i ], a[ j ] ) == a[ i ] ){
		j --;
		ans += min( a[ i ], m );
	}

	if( i - 1 == j ){
		if( i > l )
			ans += m;
		j--;
	}

	ans += merge(l , j + 1);
	j = i;
	j ++;

	while( j <= r and __gcd( a[ i ], a[ j ] ) == a[ i ] ){
		j ++;
		ans += min( a[ i ], m );
	}

	if( i + 1 == j ){
		if( i < r )
			ans += m;
		j++;
	}

	ans += merge(j - 1 , r);

	return ans;

}

ll solve(){

	n = nxt(), m = nxt();
	R(i, n) cin >> a[ i ];
	build(1, 0, n - 1);
	return merge(0, n - 1);
}

int main(){
	fastio;
	T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
