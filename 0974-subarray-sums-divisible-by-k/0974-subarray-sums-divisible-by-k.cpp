class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), prefixMod = 0, answer = 0;
        
        vector<int>modGroups(k);
        modGroups[0] = 1;
        
        for (const int &num : nums){
            prefixMod = (prefixMod + (num % k) + k) % k;
            answer += modGroups[prefixMod];
            ++modGroups[prefixMod];
        }
        
        return answer;
    }
};