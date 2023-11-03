class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int start = 0, targetLength = target.size();
        vector<string> ans;
        for (int i = 1; i <= n && start < targetLength; ++i){
            ans.push_back("Push");
            if (i == target[start])
                ++start;
            else
                ans.push_back("Pop");
        }
        
        return ans;
    }
};