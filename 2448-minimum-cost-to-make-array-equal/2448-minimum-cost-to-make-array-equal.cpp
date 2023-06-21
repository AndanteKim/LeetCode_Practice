typedef long long ll;

class Solution {
private:
    ll getCost(int base, vector<int>& nums, vector<int>& cost){
        ll total = 0;
        for (int i = 0; i < nums.size(); ++i){
            total += (ll)abs(nums[i] - base) * cost[i];
        }
        return total;
    }
    
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end());
        ll ans = getCost(nums[0], nums, cost);
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            ll cost1 = getCost(mid, nums, cost);
            ll cost2 = getCost(mid + 1, nums, cost);
            
            ans = min(cost1, cost2);
            
            if (cost1 > cost2) left = mid + 1;
            else right = mid;
        }
        
        return ans;
    }
};