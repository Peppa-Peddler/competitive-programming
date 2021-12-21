#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	vector<int>ans;
	cin >> s;
	int n = s.size(), i, j;
	i = 0, j = n - 1;
	while( j > i ){
		if( s[ i ] == '(' and s[ j ] == ')' ){
			ans.push_back( i++ );
			ans.push_back( j-- );
		}
		if( s[ i ] != '(' ) i++;
		if( s[ j ] != ')' ) j--;
	}
	sort(ans.begin(), ans.end());
	if( ans.size() == 0 ){
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[ i ] + 1 << " ";
	cout << endl;
	return 0;
}
