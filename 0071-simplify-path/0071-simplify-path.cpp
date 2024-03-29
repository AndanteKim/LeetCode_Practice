class Solution {
public:
    string simplifyPath(string path) {
        string ans = "", token;
        stringstream ss(path);
        vector<string> tokens;
        
        while (getline(ss, token, '/')){
            if (token == "." || token == "") continue;
            else if (token == ".."){
                if (tokens.size() != 0) tokens.pop_back();
            }
            else tokens.push_back(token);
        }
            
        if (tokens.size() == 0) return "/";
        for (int i = 0; i < tokens.size(); ++i){
            ans = ans + '/' + tokens[i];
        }
        return ans;
    }
};