#define ll long long

class Solution {
    bool isValid(int x, vector<int>& nums){
        ll total = 0;
        for (int i = 0; i < nums.size(); ++i){
            total += nums[i];
            if (total > (ll)x * (i + 1)) return false;
        }
        return true;
    }
    
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (isValid(mid, nums)){
                right = mid;
            }
            else left = mid + 1;
        }
        
        return left;
    }
};