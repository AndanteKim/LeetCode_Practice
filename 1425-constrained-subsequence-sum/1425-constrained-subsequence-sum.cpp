class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        int ans = nums[0];
        // {current sum, current index}
        pq.push({nums[0], 0});
        
        for (int i = 1; i < nums.size(); ++i){
            while (!pq.empty() && i - pq.top().second > k)
                pq.pop();
            
            int curr = max(0, pq.top().first) + nums[i];
            ans = max(ans, curr);
            pq.push({curr, i});
        }
        
        return ans;
    }
};