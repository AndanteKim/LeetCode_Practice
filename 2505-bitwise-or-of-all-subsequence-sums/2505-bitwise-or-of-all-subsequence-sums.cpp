class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long ans = 0, prefixSum = 0;
        
        // Iterate through each element in the input array
        for (const int num:nums){
            // Update the cumulative sum by adding the current element
            prefixSum += num;
            
            // Update the answer by performing bitwise OR with the current element and the cumulative sum
            ans |= num | prefixSum;
        }
        
        return ans;
    }
};