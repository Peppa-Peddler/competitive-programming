#include<iostream>

using namespace std;

#define MOD 1000000007

int solve(){
  long long n, fib = 1, exp = 1;
  cin >> n;
  for(long long i = 0; i < n; i ++){
    fib *= i + 1;
    fib %= MOD;
    if(i)exp *= 2;
    exp %= MOD;
  }
  fib += MOD - exp;
  fib %= MOD;
  return fib;
}

int main(){
  cout << solve() << endl;
}
