class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> freqs;
        
        for (int n:nums){
            ++freqs[n];
        }
        
        int dup = -1, missing = 1;
        for (int i = 1; i <= nums.size(); ++i){
            if (freqs.count(i)){
                if (freqs[i] == 2)
                    dup = i;
            }
            else
                missing = i;
        }
        
        return vector<int>{dup, missing};
    }
};