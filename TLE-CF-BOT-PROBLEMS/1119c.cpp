#include <iostream>

using namespace std;

#define FOR(i, n) for(int i=0;i<n;i++)

string solve(){
	int v[502][502];
	int n, m, val, count;
	cin >> n >> m;
	FOR(i,n)FOR(j,m)cin>>v[i][j];
	FOR(i,n)FOR(j,m){
		cin >> val;
		v[i][j] = v[i][j] != val;
	}
	FOR(i,n){
		count = 0;
		FOR(j,m)
			count += v[i][j];
		if(count%2) return "No";
	}
	FOR(j,m){
		count = 0;
		FOR(i,n)
			count += v[i][j];
		if(count%2) return "No";
	}
	return "Yes";

}

int main(){
	cout << solve() << endl;
}
