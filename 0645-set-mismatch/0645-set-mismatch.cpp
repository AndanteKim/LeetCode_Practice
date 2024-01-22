class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> count(mx + 1);
        
        for (int n:nums)
            ++count[n];
        
        vector<int> missing{-1, -1};
        for (int i = 1; i <= mx; ++i){
            if (count[i] == 2)
                missing[0] = i;
            
            if (count[i] == 0)
                missing[1] = i;
        }
        
        return missing[1] == -1? vector<int>{missing[0], mx + 1} : missing;
    }
};