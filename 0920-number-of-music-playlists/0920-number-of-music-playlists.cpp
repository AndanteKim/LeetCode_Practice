typedef long long ll;

class Solution {
private:
    static const int MOD = 1'000'000'007;
    vector<ll> factorial, invFactorial;
    
    ll power(ll base, int exponent){
        ll res = 1;
        while (exponent > 0){
            if (exponent & 1){
                res = (res * base) % MOD;
            }
            exponent >>= 1;
            base = (base * base) % MOD;
        }
        
        return res;
    }
    
    void precalculateFactorials(int n){
        factorial.resize(n + 1);
        invFactorial.resize(n + 1);
        factorial[0] = invFactorial[0] = 1;
        for (int i = 1; i <= n; ++i){
            factorial[i] = (factorial[i - 1] * i) % MOD;
            invFactorial[i] = power(factorial[i], MOD - 2);
        }
    }
    
public:
    int numMusicPlaylists(int n, int goal, int k) {
        precalculateFactorials(n);
        int sign = 1;
        ll ans = 0;
        for (int i = n; i >= k; --i){
            ll temp = power(i - k, goal - k);
            temp = (temp * invFactorial[n - i]) % MOD;
            temp = (temp * invFactorial[i - k]) % MOD;
            
            ans = (ans + sign * temp + MOD) % MOD;
            sign *= -1;
        }
        
        return (factorial[n] * ans) % MOD;
    }
};