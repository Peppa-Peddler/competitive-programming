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
typedef tuple<int, int, int> Node;

ll nxt() { ll x; cin >> x; return x; }

#define N 505

ll n, m, T = 1;
string s;
ii f[ N ];

Node check(int i, int j){

	swap( s[ i ], s[ j ] );

	f[ n ] = {0, 0};

	REF( i , n - 1 , 1 ){
		f[ i ] = f[ i + 1 ];

		if( s[ i ] == ')' )
			f[ i ].F++;

		else if( f[ i ].F )
			f[ i ].F--;

		else
			f[ i ].S++;
	}

	int l = 0, lm = 0;
	int ans = 0;

	R(i, n){
		if( s[ i ] == '(' ) l++;
		else l--;
		if( l < 0 )
			lm++, l = 0;
		if( l > 0 ) continue;
		if( f[ i + 1 ].F ) continue;
		if( f[ i + 1 ].S == lm )
			ans++;
	}

	swap( s[ i ], s[ j ]);

	return { ans , i , j };

}

ll solve(){
	n = nxt();
	cin >> s;

	Node ans = { 0, 0, 0 }, tmp;

	R( i, n ){
		FER( j , i , n ){
			ans = max( ans , check( i, j ) );
		}
	}

	int L, i, j;
	tie( L , i , j ) = ans;

	cout << L << endl;
	cout << i + 1 << " " << j + 1 << endl;

	return 0;
}

int main(){
	fastio;
	//T = nxt();
	//while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
