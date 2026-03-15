typedef long long ll;

class Fancy {
private:
    static constexpr int mod = 1'000'000'007;
    vector<int> v, a{1}, b{0};

public:
    Fancy() {}
    
    void append(int val) {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }

    // Fast exponentiation
    int quickMul(int x, int y) {
        int ret = 1, curr = x;

        while (y) {
            if (y & 1) ret = (ll)ret * curr % mod;
            curr = (ll)curr * curr % mod;
            y >>= 1;
        }

        return ret;
    }

    // Multiplicative inverse
    int inv(int x) {
        return quickMul(x, mod - 2);
    }
    
    void addAll(int inc) {
        b.back() = (b.back() + inc) % mod;
    }
    
    void multAll(int m) {
        a.back() = (ll)a.back() * m % mod;
        b.back() = (ll)b.back() * m % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= v.size()) return -1;

        int a0 = (ll)inv(a[idx]) * a.back() % mod;
        int b0 = (b.back() - (ll)b[idx] * a0 % mod + mod) % mod; 
        int ans = ((ll)a0 * v[idx] % mod + b0) % mod;
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */