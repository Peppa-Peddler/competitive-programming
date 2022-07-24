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

#define N N4

ll n, m, T = 1;

int q( int t, int i, int j, int x ){
	int ans;
	cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
	cin >> ans;
	return ans;
}

int Qmax(int i, int j){
	int res = q(1, i, j, n - 1);
	if( res == n - 1 )
		return q(1, j, i, n - 1);
	return res;
}

int Qmin(int i, int j){
	int res = q(2, i, j, 1);
	if( res == 2 )
		return q(2, j, i, 1);
	return res;
}

vi ans;

void solve(){

	n = nxt();

	ans.clear();

	ll A, B, C, D;

	A = Qmax( 0 , 1 );
	B = Qmin( 1 , 0 );

	C = Qmax( 0 , 2 );
	D = Qmin( 2 , 0 );

	if( C > A ){
		if( D == B ){
			ans.PB( B );
			ans.PB( A );
		} else {
			ans.PB( A );
			ans.PB( B );
		}
	} else if ( A == C ) {
		ans.PB( A );
		ans.PB( B );
	} else {
		ans.PB( B );
		ans.PB( A );
	}

	ll a = 0;
	ll b = 1;

	if( ans[ a ] < ans[ b ] )
		swap( a , b );

	for( int i = 2; i < n - n%2 ; i += 2 ){
		C = Qmax( i , i + 1 );
		D = Qmin( i + 1 , i );
		if( D > ans[ a ] ){
			A = Qmax( a , i );
			ans.PB( A );
			ans.PB( C == A ? D : C );
		} else if ( D > ans[ b ] ) {
			B = Qmax( b , i );
			ans.PB( B );
			ans.PB( C == B ? D : C );
		} else {
			B = Qmin( i , b );
			if( B != ans[ b ] ){
				ans.PB( B );
				ans.PB( C == B ? D : C );
			} else {
				ans.PB( C );
				ans.PB( D );
			}
		}
		if( ans[ a ] >= n - 1 )
			a = ans[ i ] > ans[ i + 1 ] ? i : ( i + 1 );
		if( ans[ b ] <= 2 )
			b = ans[ i ] < ans[ i + 1 ] ? i : ( i + 1 );
	}

	if( n % 2 ){
		C = Qmax( a , n - 1 );
		D = Qmin( n - 1 , a );
		ans.PB( ans[ a ] == C ? D : C );
	}

	cout << "! ";
	for(auto s: ans)
		cout << s << " ";
	cout << endl;

}

int main(){
	fastio;
	T = nxt();
	//	while(T--) cout << solve() << endl;
	while(T--) solve();
	return 0;
}
