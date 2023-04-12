class Solution {
public:
    string simplifyPath(string path) {
        vector<string> sections;
        stack<string> stack;
        string frag = "", ans = "";
        for (const char&c : path){
            if (c == '/'){
                sections.push_back(frag);
                frag.clear();
            }
            else frag.push_back(c);
        }
        if (frag != "") sections.push_back(frag);
        
        for (string& section : sections){
            if (section == ".."){
                if (!stack.empty()) stack.pop();
            }
            else if (section == "." || section == "") continue;
            else stack.push(section);
        }
        
        while (!stack.empty()){
            ans = "/" + stack.top() + ans;
            stack.pop();
        }
        return ans == ""? "/" : ans;
    }
};