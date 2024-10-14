class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap;
        
        for (int num : nums) maxHeap.push(num);
        
        long long ans = 0;
        while (k > 0 && !maxHeap.empty()){
            int curr = maxHeap.top();
            maxHeap.pop();
            ans += curr;
            curr = (curr / 3 == (double)(curr) / 3)? curr / 3 : curr / 3 + 1;
            maxHeap.push(curr);
            --k;
        }
        
        return ans;
    }
};