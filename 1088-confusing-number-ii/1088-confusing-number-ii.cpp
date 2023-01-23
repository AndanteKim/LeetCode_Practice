#define ll long long

class Solution {
    vector<int> valid{0,1,6,8,9};
    unordered_map<int, int> lookup{{0,0},{1,1},{6,9},{8,8},{9,6}};
    ll n;
public:
    void backtrack(ll v, ll rotation, ll digits, ll &count){
        if (v != 0){
            if (v != rotation) ++count;
            
            for (const auto &i:valid){
                if (v * 10 + i > this -> n) break;
                else backtrack(v * 10 + i, lookup[i] * digits + rotation, digits * 10, count);
            }
        }
    }
    
    int confusingNumberII(int n) {
        this -> n = n;
        ll count = 0;
        backtrack(1, 1, 10, count);
        backtrack(6, 9, 10, count);
        backtrack(8, 8, 10, count);
        backtrack(9, 6, 10, count);
        return count;
    }
};