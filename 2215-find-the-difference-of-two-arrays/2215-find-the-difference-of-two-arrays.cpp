class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> v1, v2;
        for (int n1 : s1){
            if (s2.find(n1) == s2.end()) v1.push_back(n1);
        }
        for (int n2 : s2){
            if (s1.find(n2) == s1.end()) v2.push_back(n2);
        }
        
        return {v1, v2};
    }
};