class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stack;
        
        for (int curr = 0; curr < height.size(); ++curr){
            while (!stack.empty() && height[curr] > height[stack.top()]){
                int top = stack.top(); stack.pop();
                if (stack.empty()) break;
                
                int dist = curr - stack.top() - 1, boundedHeight = min(height[curr], height[stack.top()]) - height[top];
                ans += dist * boundedHeight;
            }
            stack.push(curr);
        }
        
        return ans;
    }
};