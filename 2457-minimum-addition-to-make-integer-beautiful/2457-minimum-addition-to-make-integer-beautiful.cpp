typedef long long ll;

class Solution {
private:
    ll digitSum(ll n){
        ll s = 0;
        while (n > 0){
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    
public:
    long long makeIntegerBeautiful(long long n, int target) {
        ll lst = 1, add = 0;
        
        while (digitSum(n + add) > target){
            ll x = pow(10, lst);
            add = x - (n % x);
            ++lst;
        }
        
        return add;
    }
};