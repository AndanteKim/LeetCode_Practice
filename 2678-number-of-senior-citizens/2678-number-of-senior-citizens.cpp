class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        unordered_set<int> digits{'7', '8', '9'};
        
        for (string& d : details){
            if (digits.find(d[11]) != digits.end()) ++ans;
            else if (d[11] == '6' && d[12] != '0') ++ans;
        }
        
        return ans;
    }
};