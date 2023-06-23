class Solution {
private:
    int n, k;
    void backtrack(int start, string& word, vector<string>& ansList){
        if (start == n){
            ansList.push_back(word);
            return;
        }
        
        for (const char& c: vector<char>{'a','b','c'}){
            if (!word.empty() && word.back() == c) continue;
            else{
                word.push_back(c);
                backtrack(start + 1, word, ansList);
                word.pop_back();
            }
        }
        
    }
    
public:
    string getHappyString(int n, int k) {
        vector<string> ansList;
        string word = "";
        this -> n = n, this -> k = k;
        backtrack(0, word, ansList);
        
        return ansList.size() < k? "" : ansList[k - 1];
    }
};