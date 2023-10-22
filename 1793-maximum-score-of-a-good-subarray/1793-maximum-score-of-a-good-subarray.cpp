class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i){
            while (!st.empty() && nums[st.top()] > nums[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> right(n, n);
        st = stack<int>();
        for (int i = 0; i < n; ++i){
            while (!st.empty() && nums[st.top()] > nums[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i){
            if (left[i] < k && right[i] > k){
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
            }
        }
        
        return ans;
    }
};