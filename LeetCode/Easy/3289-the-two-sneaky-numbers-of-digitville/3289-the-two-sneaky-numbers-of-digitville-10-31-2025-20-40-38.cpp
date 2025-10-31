class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> count;

        for (int num : nums) ++count[num];
        
        for (const auto& [num, freq] : count){
            if (freq == 2) ans.push_back(num);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};