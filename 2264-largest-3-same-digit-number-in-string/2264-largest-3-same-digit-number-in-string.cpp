class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        vector<string> candidates;
        
        for (int i = 0; i < n - 2; ++i){
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
                candidates.push_back(string(3, num[i]));
        }

        sort(candidates.begin(), candidates.end());
        return candidates.size() == 0? "" : candidates.back();
    }
};