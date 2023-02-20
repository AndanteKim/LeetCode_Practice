class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_num;
        stack<int> st;
        for (int num2 : nums2){
            while (!st.empty() && num2 > st.top()){
                next_num[st.top()] = num2;
                st.pop();
            }
            st.push(num2);
        }
        
        while (!st.empty()){
            next_num[st.top()] = -1;
            st.pop();
        }
        
        vector<int> ans;
        for (int num1: nums1) ans.push_back(next_num[num1]);
        return ans;
    }
};