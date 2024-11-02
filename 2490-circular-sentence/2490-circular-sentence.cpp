class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word)
            words.push_back(word);
        
        int n = words.size();
        for (int i = 0; i < n; ++i){
            if (words[i % n].back() != words[(i + 1) % n][0])
                return false;
        }
        
        return true;
    }
};