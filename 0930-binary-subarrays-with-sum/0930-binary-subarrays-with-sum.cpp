class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> indices;
        indices.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) indices.push_back(i);
        }
        indices.push_back(nums.size());
        int ans = 0;
        
        if (goal == 0){
            for (int i = 0; i < indices.size()-1; ++i){
                int w = indices[i+1] - indices[i] - 1;
                ans += (w * (w+1)) / 2;
            }
            return ans;
        }
        
        for (int i = 1; i < indices.size() - goal; ++i){
            int j = i + goal - 1;
            int left = indices[i] - indices[i-1];
            int right = indices[j+1] - indices[j];
            ans += right * left;
        }
        
        return ans;
    }
};