class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tortoise = nums[0], hare = nums[0];
        
        // find the intersection point of the two runners
        while (true){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            
            if (tortoise == hare) break;
        }
        
        // find the "entrance" to the cycle
        tortoise = nums[0];
        while (tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};