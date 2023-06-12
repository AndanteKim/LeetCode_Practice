typedef long long ll;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll left = 0, right = accumulate(candies.begin(), candies.end(), 0ll) / k;
        
        while (left < right){
            ll mid = left + ((right - left + 1) >> 1), portion = 0;
            for (int candy : candies) portion += candy / mid;
            
            if (portion < k) right = mid - 1;
            else left = mid;
        }
        
        return left;
    }
};