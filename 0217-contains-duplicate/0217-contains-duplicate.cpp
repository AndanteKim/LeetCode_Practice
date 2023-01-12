class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counter;
        
        for(const auto &num : nums) ++counter[num];
        
        for (const auto c : counter){
            if (c.second > 1) return true;
        }
        
        return false;
    }
};