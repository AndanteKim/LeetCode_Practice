typedef long long ll;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        ll x;

        while (true){
            x = num1 - (ll)(num2) * k;

            if (x < k) return -1;

            if (k >= __builtin_popcountll(x)) return k;

            ++k;
        }

        return -1;
    }
};