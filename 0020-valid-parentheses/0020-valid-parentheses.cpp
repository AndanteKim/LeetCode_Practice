class Solution {
    unordered_map<char, char> match{{'}', '{'}, {']', '['}, {')', '('}};
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_set<char> front{{'{', '(', '['}};
        for (const char& c : s){
            if (front.find(c) != front.end()) stack.push(c);
            else if (!stack.empty() && match[c] == stack.top()) stack.pop();
            else return false;
        }
        return stack.empty()? true : false;
    }
};