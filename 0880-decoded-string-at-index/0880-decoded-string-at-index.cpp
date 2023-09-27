typedef long long ll;
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        ll sz = 0;
        
        // Find size = length of decoded string
        for (char& c : s){
            if (isdigit(c))
                sz *= (int) c - '0';
            else
                ++sz;
        }
        
        reverse(s.begin(), s.end());
        for (char& c : s){
            k %= sz;
            if (k == 0 && isalpha(c)){
                return string(1, c);
            }
            if (isdigit(c)){
                sz /= (int) c - '0';
            }
            else --sz;
        }
        
        return "";
    }
};