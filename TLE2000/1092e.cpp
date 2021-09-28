#include<bits/stdc++.h>

#define LL long long

#define PII pair<int, int>
#define VI vector<int>
#define PB push_back
#define PQ priority_queue

#define MP make_pair
#define F first
#define S second

#define MOD 1000000007
#define N6 1000006
#define N5 100005
#define N4 10004
#define N3 1003

#define PI 3.1415926535897932384626

#define N N5

#define clr(v, a) memset(v, a, sizeof(v))
#define all(x) x.begin(),x.end()
#define R(i, n) for(int i=0; i<n; i++)
#define len(x) ((int)(x).size())

#define bits(x) __builtin_popcount(x)
#define bitsLL(x) __builtin_popcountll(x)

#define zerosl(x) __builtin_clz(x)
#define zerosr(x) __builtin_ctz(x)

/*
⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄
*/

using namespace std;

int n, m, k, t = 1;

VI tree[ N3 ];
int dad[ N3 ];
int dis[ N3 ];

vector<PII> vals;

PII get_values( int i ){

    int id, d, l, fari = i, farj;
    queue< pair<int, PII> > Q;
    Q.push( MP(0, MP(i, -1)));

    while(!Q.empty()){
        id = Q.front().S.F;
        l = Q.front().F;
        Q.pop();
        if( dis[ id ] != -1  ) continue;
        dis[ id ] = l;
        if( dis[ id ] > dis[ fari ] ) fari = id;
        R(j, len(tree[ id ]))
            Q.push(MP( l + 1, MP(tree[ id ][ j ], -1 )));
    }

    Q.push(MP(0, MP(fari, fari)));
    farj = fari;

    while(!Q.empty()){
        id = Q.front().S.F;
        l = Q.front().F;
        d = Q.front().S.S;
        Q.pop();
        if( dad[ id ] != -1  ) continue;
        dad[ id ] = d;
        dis[ id ] = l;
        if( dis[ id ] > dis[ farj ] ) farj = id;
        R(j, len(tree[ id ]))
            Q.push(MP( l + 1, MP(tree[ id ][ j ], id )));
    }

    int centroide = farj, diameter = dis[ farj ];

    while( dis[ centroide ] != diameter/2 )
        centroide = dad[ centroide ];

    return MP( diameter, centroide);
}

LL solve(){
    cin >> n >> m;

    int a, b;

    R(i, m){
        cin >> a >> b;
        a--,b--;
        tree[ a ].PB( b );
        tree[ b ].PB( a );
    }

    R(i, n)
        dis[ i ] = dad[ i ] = -1;

    R(i, n){
        if( dis[ i ] != -1 ) continue;
        vals.PB(get_values(i));
    }

    sort(all(vals));

    int vs = len(vals);

    if( vs == 1 ){
        cout << vals[ 0 ].F << endl;
        return 0;
    }

    R(i, n)
        dis[ i ] = dad[ i ] = -1;

    R(i, vs - 1){
        tree[ vals[ vs - 1 ].S ].PB( vals[ i ].S );
        tree[ vals[ i ].S ].PB( vals[ vs - 1 ].S );
    }

    cout << get_values( vals[ vs - 1 ].S ).F << endl;

    R(i, vs - 1)
        cout << vals[ vs - 1 ].S + 1 << " " << vals[ i ].S + 1 << endl;

    return 0;
}

int main(){

    //cin >> t;
//    while(t--) cout << solve() << endl;
    while(t--) solve();

}
