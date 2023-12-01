class Solution {
private:
    string combine(vector<string>& word){
        string concatenated = "";
        for (string& part : word){
            for (char& c : part)
                concatenated.push_back(c);
        }
        
        return concatenated;
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return combine(word1) == combine(word2);
    }
};