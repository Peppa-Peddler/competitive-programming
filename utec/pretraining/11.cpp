#include<bits/stdc++.h>

#define EP emplace
#define EB emplace_back
#define PB push_back
#define PF push_front

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

#define N N5

ll n, m, T = 1, ans;

string blocked[ 8 ];

int DP( int i = 0, int mask = 0, int maskA = 0, int maskB = 0 ){
	if( i == 8 ) return 1;
	int ans = 0;
	R(j, 8){
		if( blocked[i][j] == '*'  ) continue;
		if( mask & (1 << j) ) continue;
		if( maskA & ( 1 << (i + j) ) ) continue;
		if( maskB & ( 1 << (i - j + 7) ) ) continue;
		ans += DP( i + 1, mask | (1 << j) , maskA | ( 1 << (i + j) ) , maskB | ( 1 << (i - j + 7) ) );
	}
	return ans;
}

ll solve(){
	R(i, 8)
		cin >> blocked[ i ];
	return DP();
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}