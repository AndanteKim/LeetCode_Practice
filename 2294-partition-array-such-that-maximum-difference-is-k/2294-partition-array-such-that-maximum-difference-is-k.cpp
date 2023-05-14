class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, prev = nums.back();
        while (!nums.empty()){
            int num = nums.back();
            if (prev - num > k){
                prev = num;
                ++ans;
            }
            nums.pop_back();
        }
        
        return ans;
    }
};