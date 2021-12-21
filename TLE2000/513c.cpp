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

ll n, m, T = 1, ans;

ll F[ N ];

ii v[ 6 ];

long double solve(){

	n = nxt();

	R(i, n)
		cin >> v[ i ].F >> v[ i ].S;

	FER( A , 1 , N ){
		R( i , n ){
			ll Ri, Li;
			tie( Li, Ri ) = v[ i ];

			FER( mask , 1 , 1 << n ){

				if( mask & ( 1 << i ) ) continue;

				ll Fr = 1, Rj, Lj;
				R(j, n){
					if( j == i ) continue;

					tie( Lj, Rj ) = v[ j ];
					if( mask & ( 1 << j ) ){
						if( A > Rj or A < Lj )
							Fr = 0;
					} else {
						Fr *= max( 0LL, min( A - Lj , Rj - Lj + 1 ) );
					}

				}
				F[ A ] += Fr * max( 0LL, min( Ri - A , Ri - Li + 1 ) );
			}

		}
		R( mask, 1 << n ){
			if(__builtin_popcount( mask ) < 2) continue;
			ll Fr = 1, Rj, Lj;
			R(j, n){
				tie( Lj, Rj ) = v[ j ];
				if( mask & ( 1 << j ) ){
					if( A > Rj or A < Lj )
						Fr = 0;
				} else {
					Fr *= max( 0LL, min( A - Lj , Rj - Lj + 1 ) );
				}
			}
			F[ A ] += Fr;
		}
	}

	long double ans = 0, szL, szR;

	szL = (v[ 0 ].S - v[ 0 ].F + 1)*(v[ 1 ].S - v[ 1 ].F + 1);
	szR = 1;

	FER( i , 2 , n ){
		szR *= (v[ i ].S - v[ i ].F + 1);
	}

	R(i, N){
		ans += i * (F[ i ] / szR);
	}

	ans /= szL;

	return ans;
}

int main(){
	fastio;
	//T = nxt();
	cout.precision(10);
	while(T--) cout << fixed << solve() << endl;
	//while(T--) solve();
	return 0;
}
