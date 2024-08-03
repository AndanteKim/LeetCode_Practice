class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> balance;
        
        for (int i = 0; i < target.size(); ++i){
            ++balance[arr[i]];
            --balance[target[i]];
        }
        
        for (int i = 0; i < target.size(); ++i) if (balance[arr[i]]) return false; 
        return true;
    }
};