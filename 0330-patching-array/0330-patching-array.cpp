class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0, i = 0;
        long long miss = 1;
        
        while (miss <= n){
            // miss is covered
            if (i < nums.size() && nums[i] <= miss){
                miss += nums[i++];
            }
            else{
                // patch miss to the array
                miss += miss;

                // increase the number
                ++patches;
            }
            
        }
        
        return patches;
    }
};