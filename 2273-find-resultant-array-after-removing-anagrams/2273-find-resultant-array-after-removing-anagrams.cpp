class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = "";
        int n = words.size();
        vector<string> ans;

        for (string& word : words){
            map<char, int> chars;
            for (const char& c : word) ++chars[c];
            string anagram = "";
            for (const auto& [c, freq] : chars) anagram += c + to_string(freq);

            if (anagram == prev) continue;
            prev = anagram;
            ans.push_back(word);
        }

        return ans;
    }
};