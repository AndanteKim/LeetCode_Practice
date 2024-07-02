class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        int j = 0;
        
        for (int i = 0; i < nums1.size();){
            int index = lower_bound(begin(nums2), end(nums2), nums1[i]) - begin(nums2);
            
            int count2 = 0;
            while (index < nums2.size() && nums2[index] == nums1[i]){
                ++count2;
                ++index;
            }
            
            int count1 = 0;
            while (j < nums1.size() && nums1[j] == nums1[i]){
                ++count1;
                ++j;
            }
            
            ans.insert(ans.end(), min(count1, count2), nums1[i]);
            i = j;
        }
        
        return ans;
    }
};