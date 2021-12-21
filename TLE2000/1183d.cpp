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

int a[ N ][ 2 ];

PQ < ll > Q;
vii E;

ll solve(){
	n = nxt();

	int x, y;

	R( i , n ){
		cin >> x;
		a[ x ][ 1 ]++;
	}

	R( i , n ){
		x = a[ i + 1 ][ 0 ] + a[ i + 1 ][ 1 ];
		if( x ){
			E.EB( x, a[ i + 1 ][ 1 ] );
		}
	}

	sort( all( E ) );

	ans = 0;
	ll k = n, f = 0, i = len(E) - 1;

	while( k > 0 and i >= 0 ){
		if( E[ i ].F < k ){
			if( !Q.empty() ){
				f += min(k, Q.top());
				Q.pop();
				ans += k;
			}
			k--;
		} else {
			Q.push( E[ i ].S );
			i--;
		}
	}

	while( k > 0 and !Q.empty() ){
		f += min(k, Q.top());
		Q.pop();
		ans += k;
		k--;
	}

	E.clear();
	while(!Q.empty()) Q.pop();
	R(i, n){
		a[ i + 1 ][ 0 ] = a[ i + 1 ][ 1 ] = 0;
	}

	cout << ans << " " << endl;

	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
