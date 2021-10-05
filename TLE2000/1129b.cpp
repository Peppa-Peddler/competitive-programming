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

ll solve(){

	cin >> n;

	ll up , A , B , C , L;

	if( n == 1000000000 - 1 ){

		up = 1000001950;
		A = up - n;
		C = 1735;
		L = up/C;
		B = A - C;

	} else {
		up = (n / 1000 + 2)*1000LL;
		A = up - n; C = 1000; L = up/1000;
		B = A - C;
	}


	cout << A << endl;

	R(i, C - 1) cout << "0 ";
	cout << -1 << " ";
	if( B == 1 ) cout << L << endl;
	else{
		R(i, B - 2) cout << "0 ";
		cout << L / 2 << " ";
		cout << L - L / 2 << endl;
	}

    return 0;
}

int main(){
	fastio;
    //cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();
}
