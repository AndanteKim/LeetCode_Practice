class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counter;
        
        for (const int &num: nums) ++counter[num];
        for (const auto& [key, value] : counter) if (value >= 2) return true;
            
        return false;
    }
};