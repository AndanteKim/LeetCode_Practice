class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique;
        for (int num : nums)
            if (unique.empty() || unique.back() != num)
                unique.push_back(num);
        
        for (int i = 0; i < unique.size(); ++i)
            nums[i] = unique[i];
        
        return (int)unique.size();
    }
};