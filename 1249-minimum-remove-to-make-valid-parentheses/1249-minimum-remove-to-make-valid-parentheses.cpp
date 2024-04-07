class Solution {
private:
    int n;
    string deleteInvalidString(string& str, const char openSymbol, const char closeSymbol){
        string sb = "";
        int balance = 0;
        
        for (char& c:str){
            if (c == openSymbol) ++balance;
            if (c == closeSymbol){
                if (balance == 0) continue;
                --balance;
            }
            sb.push_back(c);
        }
        
        return sb;
    }
    
public:
    string minRemoveToMakeValid(string s) {
        
        // Note that the reverse string
        this -> n = s.size();
        s = deleteInvalidString(s, '(', ')');
        reverse(s.begin(), s.end());
        s = deleteInvalidString(s, ')', '(');
        reverse(s.begin(), s.end());
        return s;
    }
};