class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        
        for(const auto &num : nums) st.insert(num);
        
        return st.size() == nums.size() ? false : true;
    }
};