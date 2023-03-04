class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> *st = new stack<int>;
        
        for (int i = 0; i < nums.size(); ++i){
            while (!st -> empty() && st -> top() > nums[i] && st -> size() + nums.size() - i > k) st -> pop();
            if (st -> size() < k) st -> push(nums[i]);
        }
        
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = st -> top();
            st -> pop();
        }
        
        return ans;
    }
};