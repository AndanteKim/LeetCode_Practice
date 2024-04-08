class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int minLimit = INT_MIN;
        
        for (int num : preorder){
            while (!st.empty() && st.top() < num){
                minLimit = st.top();
                st.pop();
            }
            
            if (num <= minLimit) return false;
            
            st.push(num);
        }
        
        return true;
    }
};