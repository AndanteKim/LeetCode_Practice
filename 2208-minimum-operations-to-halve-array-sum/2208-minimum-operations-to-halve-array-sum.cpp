class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ans = 0;
        double target = 0.0, curr;
        for (int i = 0; i < nums.size(); ++i) target += nums[i];
        target /= 2;
        priority_queue<double> pq(nums.begin(), nums.end());

        while (target > 0){
            curr = pq.top() / 2;
            pq.pop();
            target -= curr;
            pq.push(curr);
            ++ans;
        }
        
        return ans;
    }
};