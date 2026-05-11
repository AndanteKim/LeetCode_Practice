class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            stack<int> st;

            for (;num > 0; num /= 10) {
                st.push(num % 10);
            }

            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};