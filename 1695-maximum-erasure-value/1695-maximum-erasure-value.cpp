class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, vector<int>> counts;
        int ans = 0, curr = 0, left = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            if (counts[nums[right]].empty()){
                curr += nums[right];
                counts[nums[right]].push_back(right);
            }
            else{
                while (left <= counts[nums[right]].back()){
                    curr -= nums[left];
                    ++left;
                }
                counts[nums[right]].push_back(right);
                curr += nums[right];
            }
            ans = max(ans, curr);
        }
        
        return ans;
    }
};