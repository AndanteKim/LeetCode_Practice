class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){return a.size() > b.size();});
        unordered_set<string> ans, seen;

        for (const string& subStr : words){
            for (const string& word : seen){
                if (word.find(subStr) != string::npos)
                    ans.insert(subStr);
            }
            seen.insert(subStr);
        }

        return vector<string>(ans.begin(), ans.end());
    }
};