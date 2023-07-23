class Solution {
public:
    string parseTernary(string expression) {
        auto isValidAtomic = [](string s){
            return (s[0] == 'T' || s[0] == 'F') && s[1] == '?' && \
                ((s[2] >= '0' && s[2] <= '9') || s[2] == 'T' || s[2] == 'F') && s[3] == ':'\
                && ((s[4] >= 0 && s[4] <= '9') || s[4] == 'T' || s[4] == 'F');
        };
        
        auto solveAtomic = [](string s){
            return s[0] == 'T' ? s[2] : s[4];
        };
        
        while (expression.size() != 1){
            int j = expression.size() - 1;
            while (!isValidAtomic(expression.substr(j - 4, 5))) --j;
            expression = expression.substr(0, j - 4) + solveAtomic(expression.substr(j - 4, 5)) + expression.substr(j + 1);
        }
        
        return expression;
    }
};