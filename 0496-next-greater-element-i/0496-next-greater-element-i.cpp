class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums2_table;
        int length1 = nums1.size(), length2 = nums2.size(); 
        vector<int> ans;
        for (int i = 0; i < length2; ++i) nums2_table[nums2[i]] = i;
        
        for (int i = 0; i < length1; ++i){
            try {
                for (int j = nums2_table[nums1[i]]; j < length2; ++j){
                    if (nums1[i] < nums2[j]) {ans.push_back(nums2[j]); break;}
                    if (j == length2-1) ans.push_back(-1);
                } 
            }
            
            catch(...){
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};