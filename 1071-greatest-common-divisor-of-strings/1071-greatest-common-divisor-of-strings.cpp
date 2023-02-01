class Solution {
public:
    int gcd(int a, int b){
        
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        
        int max_length = gcd(str1.size(), str2.size());
        return str1.substr(0, max_length);
    }
};