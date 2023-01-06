class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m_lookup;
        int length1 = nums1.size(), length2 = nums2.size(); 
        vector<int> ans(length1, 0);
        stack<int> st;
        
        for (int i = 0; i < length2; ++i){
            while ((!st.empty()) && nums2[i] > st.top()){
                m_lookup[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        while (!st.empty()){
            m_lookup[st.top()] = -1;
            st.pop();
        }
        
        for (int i = 0; i < length1; ++i) ans[i] = m_lookup[nums1[i]];
        
        return ans;
    }
};