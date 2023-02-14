class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        if (n < m) return addBinary(b, a);
        
        int L = max(n, m), carry = 0, j = m - 1;
        string ans;
        for (int i = L - 1; i >= 0; --i){
            if (a[i] == '1') ++carry;
            if (j >= 0 && b[j--] == '1') ++carry;
            if (carry % 2 == 1) ans = "1" + ans;
            else ans = "0" + ans;
            carry /= 2;
        }
        
        if (carry == 1) ans = "1" + ans;  
        
        return ans;
    }
};