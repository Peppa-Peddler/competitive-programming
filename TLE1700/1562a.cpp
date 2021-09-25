#include<iostream>

using namespace std;

int main(){
  int t, l, r, a;
  cin >> t;
  while(t--){
    cin >> l >> r;
    a = r/2 + r%2;
    if( a >= l ){
      cout << a - 1 << endl;
    } else {
      cout << r - l << endl;
    }
  }
}
