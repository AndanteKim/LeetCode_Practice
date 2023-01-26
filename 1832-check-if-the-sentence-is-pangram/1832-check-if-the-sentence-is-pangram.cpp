class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> characters(sentence.begin(), sentence.end());
        
        return characters.size() == 26? true : false; 
    }
};