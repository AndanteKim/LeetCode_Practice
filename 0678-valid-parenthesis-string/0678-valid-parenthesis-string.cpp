class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openBracket, asterisks;
        
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(') openBracket.push(i);
            else if (s[i] == ')'){
                if (openBracket.empty() && asterisks.empty()) return false;
                
                if (!openBracket.empty()) openBracket.pop();
                else asterisks.pop();
            }
            else
                asterisks.push(i);
        }
        
        // Check whether the order of openBracket goes first or not
        while (!openBracket.empty() && !asterisks.empty()){
            if (openBracket.top() > asterisks.top())
                return false;
            openBracket.pop();
            asterisks.pop();
        }
        
        return (openBracket.empty())? true:false;
    }
};