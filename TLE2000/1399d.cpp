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

string s;
int pos[ 2*N5 ];
stack < int > ids[ 2 ];

ll solve(){

	cin >> n >> s;

	ans = 0;
	R(i, n){
		bool x = s[ i ] == '1';
		ids[ x ].push( i );
		if( ids[ 1 - x ].empty() ){
			pos[ i ] = 1 + ans++;
		} else {
			pos[ i ] = pos[ ids[ 1 - x ].top() ];
			ids[ 1 - x ].pop();
		}
	}

	R(i, 2) while( !ids[ i ].empty() ) ids[ i ].pop();
	
	cout << ans << endl;
	R(i, n)
		cout << pos[ i ] << " ";
	cout << endl;
	return 0;
}

int main(){
	fastio;
    cin >> t;
    //while(t--) cout << solve() << endl;
    while(t--) solve();
}
