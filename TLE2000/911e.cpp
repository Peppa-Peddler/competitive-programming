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
ll v[ N ];
ll vis[ N ];
ll a[ N ];
int t[ 4*N ];

void END(){
	cout << -1 << endl;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = max( t[v*2] , t[v*2+1] );
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2, tl, tm, l, min(r, tm)),
			   sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        t[v] = max( t[v*2] , t[v*2+1] );
    }
}

void erase( int pos ){
	update( 1, 0, n + 1, pos );
}

int maxmen( int pos ){
	return sum( 1 , 0, n + 1 , 0 , pos - 1 );
}

void solve(){
	n = nxt();
	m = nxt();

	R(i, m) v[ i ] = nxt();

	R(i, n + 1) a[ i ] = i;
	build( 1 , 0 , n + 1);

	int search = 1;
	stack < int > s;
	vi ans;

	s.push( n + 1 );

	int i = 0, q;

	while( search <= n ){
		if( vis[ search ] ){
			if( s.top() != search ) return END();
			s.pop();
			search ++;
			continue;
   		}
		if( i < m ){
			s.push( v[ i ] );
			ans.PB( v[ i ] );
			erase( v[ i ] );
			vis[ v[ i++ ] ] = 1;
			continue;
		}

		q = maxmen( s.top() );

		if( !q ) return END();

		s.push( q );
		vis[ q ] = 1;
		ans.PB( q );
		erase( q );
	}

	R(i, n)
		cout << ans[ i ] << " ";
	cout << endl;

}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
