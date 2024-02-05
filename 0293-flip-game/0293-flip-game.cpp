class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        int n = currentState.size();
        
        for (int i = 0; i < n - 1; ++i){
            if (currentState[i] == '+' && currentState[i + 1] == '+'){
                ans.push_back(currentState.substr(0, i) + "--" + currentState.substr(i + 2));
            }
        }
        
        return ans;
    }
};