class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        stack<int> *st = new stack<int>;
        
        for (int right = 0; right <= n; ++right){
            while (!st -> empty() && (right == n || nums[st -> top()] >= nums[right])){
                int mid = st -> top();
                st -> pop();
                int left = st -> empty()? -1 : st -> top(); 
                ans -= (long long) nums[mid] * (mid - left) * (right - mid);
            }
            st -> push(right);
        }
        
        st -> pop();
        for (int right = 0; right <= n; ++right){
            while (!st -> empty() && (right == n || nums[st -> top()] <= nums[right])){
                int mid = st -> top();
                st -> pop();
                int left = st -> empty()? -1 : st -> top();
                ans += (long long)nums[mid] * (mid - left) * (right - mid);
            }
            st -> push(right);
        }
        
        return ans;
    }
};