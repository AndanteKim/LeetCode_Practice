class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> invert_map({{0,0}, {1,1},{6,9},{8,8},{9,6}});
        int invert_number = 0, n_copy = n, res;
        
        while(n_copy){
            res = n_copy % 10;
            if (invert_map.find(res) == invert_map.end()) return false;
            invert_number = invert_number * 10 + invert_map[res];
            n_copy /= 10;
        }
        
        return invert_number != n;
    }
};