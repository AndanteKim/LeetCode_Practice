class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        stack<int> st;
        
        for (int curr = 0; curr < n; ++curr){
            while (!st.empty() && height[curr] > height[st.top()]){
                int right = st.top();
                st.pop();
                if (st.empty())
                    break;
                
                int dist = curr - st.top() - 1;
                int boundedHeight = min(height[curr], height[st.top()]) - height[right];
                
                ans += dist * boundedHeight;
            }
            st.push(curr);
        }
        
        return ans;
    }
};