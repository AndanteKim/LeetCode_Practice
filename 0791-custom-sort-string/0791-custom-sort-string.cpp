class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(), [&order](char lhs, char rhs) {
            return order.find(lhs) < order.find(rhs);
        });
        
        return s;
    }
};