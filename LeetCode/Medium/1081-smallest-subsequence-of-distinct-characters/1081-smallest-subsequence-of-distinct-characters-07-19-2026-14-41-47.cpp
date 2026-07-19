class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> visited(26), counts(26);
    
        for (const char& ch : s) ++counts[ch - 'a'];

        string stk = "";
        for (const char& ch : s) {
            int i = ch - 'a';

            if (!visited[i]) {
                while (!stk.empty() && stk.back() > ch) {
                    int topIdx = stk.back() - 97;

                    if (counts[topIdx] > 0) {
                        stk.pop_back();
                        visited[topIdx] = 0;
                    }
                    else break;
                }
                visited[i] = 1;
                stk.push_back(ch);
            }
            --counts[i];
        }

        return stk;
    }
};