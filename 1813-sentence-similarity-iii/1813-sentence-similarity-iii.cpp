class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // If words in s1 are more than s2, swap them and return the answer.
        if (sentence1.size() > sentence2.size())
            return areSentencesSimilar(sentence2, sentence1);
        
        // Convert sentences to lists of words
        istringstream iss1(sentence1), iss2(sentence2);
        vector<string> s1Words, s2Words;
        string word;
        while (iss1 >> word) s1Words.push_back(word);
        while (iss2 >> word) s2Words.push_back(word);
        
        // Find the maximum words matching from the beginning.
        int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;
        while (start < s1Words.size() && s1Words[start] == s2Words[start])
            ++start;
        
        // Find the maximum words matching in the end.
        while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2]){
            --ends1;
            --ends2;
        }
        
        // If ends1 index is less than start, then sentence is similar.
        return ends1 < start;
    }
};