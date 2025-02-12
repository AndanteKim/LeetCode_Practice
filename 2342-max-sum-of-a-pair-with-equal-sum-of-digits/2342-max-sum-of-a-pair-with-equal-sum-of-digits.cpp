class Solution {
private:
    int findSumDigits(int num){
        int ans = 0;

        while (num > 0){
            ans += num % 10;
            num /= 10;
        }

        return ans;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>>> seen;
        for (int num : nums){
            seen[findSumDigits(num)].push(num);
        }

        int ans = -1;
        for (auto& [num, maxHeap] : seen){
            if (maxHeap.size() >= 2){
                int pairSum = maxHeap.top(); maxHeap.pop();
                pairSum += maxHeap.top(); maxHeap.pop();
                ans = max(ans, pairSum);
            }
        }

        return ans;
    }
};