typedef long long ll;

class Solution {
private:
    ll convert(ll num){
        string s = to_string(num);
        int n = s.size();
        int l = (n - 1) >> 1, r = n >> 1;
        
        while (l >= 0)
            s[r++] = s[l--];
        
        return stoll(s);
    }
    
    ll nextPalindrome(ll num){
        ll left = 0, right = num, ans = LLONG_MIN;
        
        while (left <= right){
            ll mid = left + ((right - left) >> 1);
            ll palin = convert(mid);
            if (palin < num){
                left = mid + 1;
                ans = palin;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
    
    ll prevPalindrome(ll num){
        ll left = num, right = 1e18, ans = LLONG_MIN;
        
        while (left <= right){
            ll mid = left + ((right - left) >> 1);
            ll palin = convert(mid);
            
            if (palin > num){
                ans = palin;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
    
public:
    string nearestPalindromic(string n) {
        ll num = stoll(n);
        ll a = nextPalindrome(num), b = prevPalindrome(num);
        return (abs(a - num) <= abs(b - num))? to_string(a) : to_string(b);
    }
};