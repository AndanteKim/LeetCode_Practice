class Solution {
private:
    bool isValid(string& pString){
        int leftCount = 0;
        
        for (const char& p : pString){
            if (p == '(')
                ++leftCount;
            else
                --leftCount;
            
            if (leftCount < 0) return false;
        }
        
        return leftCount == 0;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        queue<string> queue;
        queue.push("");
        vector<string> ans;
        
        while (!queue.empty()){
            auto currStr = queue.front(); queue.pop();
            
            // If the length of current string is 2 * n, add it to 'answer' if it's valid.
            if (currStr.size() == 2 * n){
                if (isValid(currStr))
                    ans.push_back(currStr);
                continue;
            }
            
            queue.push(currStr + "(");
            queue.push(currStr + ")");
        }
        
        return ans;
    }
};