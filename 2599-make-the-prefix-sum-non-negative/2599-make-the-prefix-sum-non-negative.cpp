class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int ans = 0;
        long prefixSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums){
            // Push the negative elements to the min heap.
            if (num < 0) minHeap.push(num);
            
            prefixSum += num;

            // Pop the minimum element from the heap and subtract from the sum.
            if (prefixSum < 0){
                prefixSum -= minHeap.top(); minHeap.pop();
                
                // Increment the operations required.
                ++ans;
            }

        }
        
        return ans;
    }
};