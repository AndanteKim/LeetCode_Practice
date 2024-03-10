class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> g1(nums1.begin(), nums1.end());
        vector<int> common;
        
        for (int n2:nums2){
            if (g1.find(n2) != g1.end()){
                common.push_back(n2);
                g1.erase(n2);
            }
        }
        
        return common;
    }
};