# Modular Inverse

```c++
#define MOD 1000000007

LL binpow( LL a, LL e ){
  LL ans = 1;
  while( e ){
    if( e & 1 ) ans = ans * a % MOD;
    a = a * a % MOD; e >>= 1;
  }
  return ans;
}
```

Pequeño teorema de fermat:

` a^( P - 2 ) = a^(-1) (mod P) `

```c++
LL inv( LL a ) { return binpow( a, P - 2 ); }
```
