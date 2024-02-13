class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for (string& word:words){
            int i = 0, j = word.size() - 1;
            bool isPal = true;
            
            while (i <= j){
                if (word[i++] != word[j--]){
                    isPal = false;
                    break;
                }
            }
            
            if (isPal)
                return word;
        }
        
        return "";
    }
};