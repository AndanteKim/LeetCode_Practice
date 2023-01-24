class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, max_len = 0, curr = 0, changed = 0;
        int right_cost, left_cost;
        for (int right = 0; right < s.size(); ++right){
            right_cost = abs((int)(s[right] - '0') - (int)(t[right] - '0'));
            if (curr + right_cost <= maxCost){
                curr += right_cost;
                ++changed;
            }
            else{
                while(left < right){
                    left_cost = abs((int)(s[left] - '0') - (int)(t[left] - '0'));
                    if (left_cost <= maxCost){
                        curr -= left_cost;
                        --changed;
                    }
                    ++left;
                    if (curr + right_cost <= maxCost){
                        curr += right_cost;
                        ++changed;
                        break;
                    }
                }
            }
            max_len = max(max_len, changed);
        }
        
        return max_len;
    }
};