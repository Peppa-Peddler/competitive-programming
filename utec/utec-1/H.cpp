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

const int N = 15000000;
vector<int> lp(N+1);
vector<int> pr;
vector<int> F(N, 0);
vector<int> O, Q;

ll n, m, T = 1, ans;

void criba(){
	for (int i=2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

ll solve(){

	n = nxt();
	ll g = 0;

	R(i, n){
		cin >> m;
		g = __gcd(m, g);
		O.PB(m);
	}

	for(auto s: O){
		if( s / g != 1 )
			Q.PB( s / g );
		else
			ans++;
	}

	if(len(Q) == 0)
		return -1;

	criba();

	for(auto s: Q){
		while( lp[ s ] > 0 ){
			m = lp[ s ];
			F[ m ] ++;
			while( s % m == 0 )
				s /= m;
		}
		if( s > 1 )
			F[ s ]++;
	}

	return ans + len( Q ) - *max_element(all(F));
}

int main(){
	fastio;
	//T = nxt();
	while(T--) cout << solve() << endl;
	//while(T--) solve();
	return 0;
}
