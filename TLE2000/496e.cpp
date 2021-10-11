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

ll n, m, t = 1;

#define Nmax 2*N5

int BIT[ Nmax ];

void upd(int x, int val = 1){
	for(; x <= n; x += x&-x) BIT[x] += val;
}

int qry(int x) {
	int sum = 0;
	for(; x > 0; x -= x&-x) sum += BIT[x];
	return sum;
}

void bit_clr(){
	for(int i = 0; i <= n; i++) BIT[ i ] = 0;
}

vii seg;
vi ans;

ll solve(){

	ll a, b;
	cin >> n;
	bit_clr();

	R(i, n){
		cin >> a >> b;
		seg.EB( a , b );
	}

	sort( all(seg) );

	REF(i, len(seg) - 1, 0){
		ans.PB( query( seg[ i ].S ) );
	}

	for( auto v: ans ){
		cout << v << endl;
	}

    return 0;
}

int main(){
	fastio;
    //cin >> t;
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
