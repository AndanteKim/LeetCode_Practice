class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        
        for (string& log : logs){
            if (log == "../")
                ans = max(0, ans - 1);
            else if (log == "./")
                continue;
            else
                ++ans;
        }
        
        return ans;
    }
};