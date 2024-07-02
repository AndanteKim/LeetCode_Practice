class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;
        unordered_set<int> intersection;
        for (int num : nums1) {
            ++freq1[num];
            intersection.insert(num);
        }
        for (int num : nums2){
            ++freq2[num];
            intersection.insert(num);
        }
        
        vector<int> ans;
        for (int n : intersection){
            for (int i = 0; i < min(freq1[n], freq2[n]); ++i)
                ans.push_back(n);
        }
        
        return ans;
    }
};