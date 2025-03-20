class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Store indices of flip operations
        // Number of operations performed
        int ans = 0;
        queue<int> flipQueue;

        for (int i = 0; i < nums.size(); ++i){
            // Remove expired flips (older than 3 indices)
            while (!flipQueue.empty() && i > flipQueue.front() + 2)
                flipQueue.pop();

            // If the current element needs flipping
            if ((nums[i] + flipQueue.size()) % 2 == 0){
                // Cannot flip a full triplet
                if (i + 2 >= nums.size()) return -1;
                ++ans;
                flipQueue.push(i);
            }
        }

        return ans;
    }
};