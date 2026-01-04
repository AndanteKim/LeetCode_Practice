class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        istringstream ss(logs[0]);
        vector<string> words; string word; char delimiter = ':';

        while (getline(ss, word, delimiter)) {
            words.push_back(word);
        }

        st.push(stoi(words[0]));
        int prev = stoi(words[2]);
        words.clear();
        ss.clear();

        for (int i = 1; i < logs.size(); ++i) {
            ss.str(logs[i]);
            while (getline(ss, word, delimiter)) words.push_back(word);
            
            if (words[1] == "start") {
                if (!st.empty())
                    ans[st.top()] += stoi(words[2]) - prev;

                st.push(stoi(words[0]));
                prev = stoi(words[2]);
            }
            else {
                ans[st.top()] += stoi(words[2]) - prev + 1;
                st.pop();
                prev = stoi(words[2]) + 1;
            }

            words.clear();
            ss.clear();
        }

        return ans;
    }
};