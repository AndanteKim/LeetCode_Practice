typedef long long ll;

class Solution {
    ll getSum(int index, int value, int n){
        ll count = 0;
        
        if (value > index)
            count += (ll)(2 * value - index) * (index + 1) / 2;
        else
            count += (ll)(value + 1) * value / 2 + index - value + 1;
        
        if (value >= n - index)
            count += (ll)(2 * value - n + 1 + index) * (n - index) / 2;
        else
            count += (ll)(value + 1) * value / 2 + n - index - value;
        
        return count - value;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        
        while (left < right){
            int mid = (left + right + 1) / 2;
            
            if (getSum(index, mid, n) <= maxSum) left = mid;
            else right = mid - 1;
            
        }
        
        return left;
    }
};