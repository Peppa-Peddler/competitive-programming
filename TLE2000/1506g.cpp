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

#define N ('z'-'a'+ 5)

ll n, m, T = 1;

graph G( N );
vi ans;
string s;
bool used[ N ];

ll solve(){

	ans.clear();
	R(i, N){
		G[ i ].clear();
		used[ i ] = 1;
	}

	cin >> s;
	n = len( s );

	R(i, n){
		G[ s[ i ] - 'a' ].PB( i );
		used[ s[ i ] - 'a' ] = 0;
	}

	int SZ = 0, IDX = 0, A, l, r, mid;
	bool FL;
	R(i, N)
		SZ += (used[ i ] == 0);

	R(i, SZ){
		REF( c , N - 1 , 0 ){
			if( used[ c ] ) continue;
			A = *lower_bound( all( G[ c ] ), IDX );
			FL = true;
			R( v , N ){
				if( used[ v ] ) continue;
				if( v == c ) continue;
				l = lower_bound( all( G[ v ] ), IDX ) - begin( G[ v ] );
				if( G[ v ][ l ] > A ) continue;
				r = len( G[ v ] );
				while( r - l > 1 ){
					mid = ( r + l ) / 2;
					if( G[ v ][ mid ] < A ) l = mid;
					else r = mid;
				}
				if( r == len( G[ v ] ) ){
					FL = false;
					break;
				}
			}
			if( FL ){
				ans.PB( c );
				used[ c ] = 1;
				IDX = A + 1;
				break;
			}
		}
	}

	for(auto s: ans)
		cout << (char)(s + 'a');
	cout << endl;

	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
