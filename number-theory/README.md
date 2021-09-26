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

Precalcular módulo inverso hasta NMAX, factorial y factorial inverso

```c++
int INV[ N5 ];
LL F[ N5 ];
LL FI[ N5 ];

void prefac(int Nmax, int mod){
  INV[ 1 ] = 1;
  for( LL i = 2; i < Nmax ; i++ )
    INV[ i ] = mod - (LL)( mod / i ) * INV[ mod % i ] % mod;

  F[ 0 ] = 1;
  for( LL i = 1 ; i < Nmax ; i++ )
    F[ i ] = F[ i - 1 ]*i % mod;

  FI[ 0 ] = 1;
  for( LL i = 1 ; i < Nmax ; i++ )
    FI[ i ] = FI[ i - 1 ]*INV[ i ] % mod;
}
```
Combinatoria: nCk mod P

```c++
LL C( LL n, LL k, int mod ){
  if( n < k ) return 0;
  return F[ n ] * FI[ k ] % mod * FI[ n - k ] % mod;
}
```

# Criba

```c++
int primes[ N5 ];
void criba(int *prime, int Nmax){
  for(int i = 0; i < Nmax; i++) prime[ i ] = -1;
  for(int i = 4; i < Nmax; i+=2) prime[ i ] = 2;
  for(LL i = 3; i*i < Nmax; i+=2)
    if( prime[ i ] == -1 )
      for(LL j = i*i; j < Nmax; j += 2*i)
        if( prime[ j ] == -1 )
          prime[ j ] = i;
}

//criba(primes, N5);
```
