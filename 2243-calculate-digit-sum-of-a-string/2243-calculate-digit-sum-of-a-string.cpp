class Solution {
public:
    string digitSum(string s, int k) {
        string ans = s;
        
        while (ans.size() > k) {
            string nxt = "";
            for (int i = 0; i < ans.size(); i += k){
                int curr = 0;
                for (int j = i; j < min((int)ans.size(), i + k); ++j)
                    curr += ans[j] - 48;
                nxt.append(to_string(curr));
            }
            ans = nxt;
        }

        return ans;
    }
};