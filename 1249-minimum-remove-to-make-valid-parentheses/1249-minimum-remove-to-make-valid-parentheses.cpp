class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> indicesToRemove;
        
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')'){
                if (st.empty()) indicesToRemove.insert(i);
                else st.pop();
            }
        }
        
        while (!st.empty()){
            indicesToRemove.insert(st.top());
            st.pop();
        }
        
        string ans = "";
        for (int i = 0; i < s.size(); ++i){
            if (indicesToRemove.find(i) != indicesToRemove.end())
                continue;
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};