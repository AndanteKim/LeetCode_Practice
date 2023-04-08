class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> M1, M2;
        for (int i = 0; i < nums1.size(); ++i){
            M1[nums1[i]] = i;
            M2[nums2[i]] = i;
        }
        
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) ans.push_back(M2[nums1[i]]);
        return ans;
    }
};