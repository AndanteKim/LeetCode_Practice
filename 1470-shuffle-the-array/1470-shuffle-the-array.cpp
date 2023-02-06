class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x_sec = nums.size() / 2, y_sec = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < x_sec; ++i){
            int x_n = nums[i];
            int y_n = nums[i + x_sec];
            ans.insert(ans.end(), {x_n, y_n});
        }
        return ans;
    }
};