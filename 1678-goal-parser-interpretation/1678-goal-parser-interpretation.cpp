class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int i = 0;
        
        while (i < command.size()){
            if (isalpha(command[i])){
                ans += command[i];
                ++i;
                continue;
            }
            if (command[i] == '(' && command[i+1] == ')'){
                ans += 'o';
                i += 2;
            }
            else ++i;
        }
        return ans;
    }
};