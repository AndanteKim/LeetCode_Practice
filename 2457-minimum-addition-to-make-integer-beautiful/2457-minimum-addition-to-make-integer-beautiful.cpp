typedef long long ll;

class Solution {
private:
    ll digitSum(ll num){
        ll s = 0;
        while (num > 0){
            s += num % 10;
            num /= 10;
        }
        return s;
    }
    
public:
    long long makeIntegerBeautiful(long long n, int target) {
        ll num = n, digit = 10;
        if (digitSum(n) <= target) return 0;
        while (digitSum(n) > target){
            if (n % digit == 0) digit *= 10;
            n = (n / digit + 1) * digit;
            digit *= 10;
        }
        return n - num;
    }
};