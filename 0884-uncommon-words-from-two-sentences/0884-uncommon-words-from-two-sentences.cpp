class Solution {
private:
    void getWords(vector<string>& wordSplit, string& s){
        stringstream ss(s);
        string word = "";
        
        while (ss >> word){
            wordSplit.push_back(word);
        }
    }
    
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freqWords;
        vector<string> s1Split, s2Split;
        
        getWords(s1Split, s1);
        getWords(s2Split, s2);
        
        for (const auto& word : s1Split)
            ++freqWords[word];
        
        for (const auto& word : s2Split)
            ++freqWords[word];
        
        vector<string> ans;
        for (auto& [word, freq] : freqWords){
            if (freq == 1)
                ans.push_back(word);
        }
        
        return ans;
    }
};