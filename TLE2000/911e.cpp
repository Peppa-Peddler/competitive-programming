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

ll n, m, t = 1, ans;

int BIT[ N ];
int Bmax[ N ];
int Bmin[ N ];

int suma(int a, int b){ return a + b; }
int mayor(int a, int b){ return max(a, b); }
int menor(int a, int b){ if(!a or !b) return max(a, b); return min(a, b); }

int v[ N ];

void upd( int x, int val = 1, function<int(int, int)> f = suma , int *fen = BIT ){
	for(; x <= n; x += x&-x) fen[x] = f( fen[ x ], val );
}

int qry(int x, function<int(int, int)> f = suma , int *fen = BIT) {
	int sum = 0;
	for(; x > 0; x -= x&-x) sum = f(sum, fen[x]);
	return sum;
}

int getmin(int x){ return qry(x, menor, Bmin); }
int getmax(int x){ return qry(x, mayor, Bmax); }

ll solve(){
	cin >> n;
	R(i, n) cin >> v[ i ];

	R(i, n) {
		upd( i + 1 , v[ i ], mayor, Bmax );
		upd( i + 1 , v[ i ], menor, Bmin );
	}



    return 0;
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
