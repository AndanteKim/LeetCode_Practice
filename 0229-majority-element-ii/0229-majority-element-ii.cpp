class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        vector<int> ans;
        
        for (int num : nums){
            ++freq[num];
        }
        
        for (auto& [k, v] : freq){
            if (v > n / 3)
                ans.push_back(k);
        }
        
        return ans;
    }
};