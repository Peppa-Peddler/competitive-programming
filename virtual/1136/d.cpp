#include<bits/stdc++.h>

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

#define fill(x, v) memset(x, v, sizeof(x))
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

#define N N5

ll n, m, t = 1, ans;

int id[ 3*N5 ];

set <int> adj[ 3*N5 ];

ll solve(){
	cin >> n >> m;

	int val = 0;
	int a, b;
	
	R(i, n){
		cin >> val;
		id[ val ] = i;
	}

	R(i, m){
		cin >> a >> b;
		if( id[ a ] > id[ b ] ) continue;
		adj[ id[ a ] ].insert( id[ b ] );
	}
	
	set < int > se;
	se.insert( n - 1 );
	
	int ans = 0;
	
	for( int i = n - 2; i >= 0; i-- ){
		bool check = true;
		for (auto it = se.begin(); it != se.end(); ++it) {
			if( !adj[ i ].count( *it ) ){
				check = false;
				break;
			}
		}
		if( !check ){
			se.insert( i );
		} else {
			ans++;
		}
	}
	
    return ans;
}


int main(){
	fastio;
    //cin >> t;
	while(t--) cout << solve() << endl;
    //while(t--) solve();
}
