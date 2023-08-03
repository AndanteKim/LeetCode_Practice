class Solution {
private:
    int n;
    void backtrack(vector<string>& ans, int start, string& curr, string& digits, unordered_map<char, string>& letters){
        if (curr.size() == this -> n){
            ans.push_back(curr);
            return;
        }
        
        for (char& letter : letters[digits[start]]){
            curr.push_back(letter);
            backtrack(ans, start + 1, curr, digits, letters);
            curr.pop_back();
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> letters{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},\
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        string curr = "";
        this -> n = digits.size();
        if (this -> n == 0) return {};
        backtrack(ans, 0, curr, digits, letters);
        return ans;
    }
};