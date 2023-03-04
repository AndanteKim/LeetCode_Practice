class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> *st = new stack<int>;
        vector<int> ans(heights.size(), 0);
        
        for (int i = 0; i < heights.size(); ++i){
            while (!st -> empty() && heights[st -> top()] <= heights[i]){
                ++ans[st -> top()];
                st -> pop();
            }
            if (!st -> empty()) ++ans[st -> top()];
            
            st -> push(i);
        }
        return ans;
    }
};