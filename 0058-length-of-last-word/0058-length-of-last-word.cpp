class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        stack<string> words;
        
        while (ss >> word){
            words.push(word);
        }
        
        return words.top().size();
    }
};