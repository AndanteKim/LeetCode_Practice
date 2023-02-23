class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        int n = s.size();
        vector<char> suffixMin(n);
        for (int i = n - 1; i >= 0; --i){
            if (i == n - 1) suffixMin[i] = s[i];
            else suffixMin[i] = min(s[i], suffixMin[i+1]);
        }
        
        stack<char> t;
        for (int i = 0; i < n; ++i){
            t.push(s[i]);
            while (!t.empty() && (i == n - 1 || t.top() <= suffixMin[i+1])){
                ans += t.top();
                t.pop();
            }
        }
        
        return ans;
    }
};