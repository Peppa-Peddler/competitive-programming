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

ll p[ 2*N6 ];

void pre(){
	
	p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;
	
	ll h, nh, f, tmp;
	h = nh = 1; f = 0;
	
	for( int i = 3; i < 2*N6 ; i++ ){
		tmp = h;
		h = nh;
		nh = (nh + 2ll*tmp);
		nh %= MOD7;
		f = tmp;
		p[ i ] = p[ i - 3 ] + f;
		p[ i ] %= MOD7;
	}
}

ll solve(){
	cin >> n;
	return (4ll*p[ n ])%MOD7;
}

int main(){
	fastio;
    cin >> t;
	pre();
	
    while(t--) cout << solve() << endl;
    //while(t--) solve();
}
