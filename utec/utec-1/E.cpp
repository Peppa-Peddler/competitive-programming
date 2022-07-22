#include<iostream>
#include<vector>
#include<algorithm>

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
typedef vector<ll> vi;
ll nxt() { ll x; cin >> x; return x; }

#define N N5

ll n, m, T = 1, ans;

vi d, t;

ll solve(int id){
	n = nxt();

	ll a = 0, b = 0, x, y, i;
	vi A, B;

	while( n % 2 == 0 ) n /= 2, a++;
	while( n % 3 == 0 ) n /= 3, b++;

	while( n > 1 ){
		i = 0;
		while( n < d[ i ] or n % 3 != d[ i ] % 3 ) i++;
		n -= d[ i ];
		A.PB( 31 - i + a );
		B.PB( b );
		while( n % 2 == 0 ) n /= 2, a++;
		while( n % 3 == 0 ) n /= 3, b++;
	}

	if( n == 1 ){
		A.PB( a );
		B.PB( b );
	}

	cout << id << " " << len(A) << " ";

	R(i, len(A)){
		cout << "[" << A[ i ] << "," << B[ i ] << "]" << " ";
	}

	cout << endl;
	return 0;
}

int main(){
	fastio;
	T = nxt();
	//while(T--) cout << solve() << endl;

	R(i, 32)
		d.PB( 1ll << i );

	reverse(all(d));

	R(i, T) solve( i + 1 );
	return 0;
}
