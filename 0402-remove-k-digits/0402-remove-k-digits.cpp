class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        
        // Construct a monotone increasing sequence of digits
        for (char& c : num){
            while (k > 0 && !st.empty() && c < st.back()){
                st.pop_back();
                --k;
            }
            
            st.push_back(c);
        }
        
        // Trunk the remaining K digits at the end
        // in the case k == 0: return the entire list
        while (k-- > 0) st.pop_back();
        
        string ans = "";
        // trip the leading zeros
        bool leadingZero = true;
        for (char& c : st) {
            if (leadingZero && c == '0')
                continue;
            
            leadingZero = false;
            ans.push_back(c);
        }
            
        return ans.empty()? "0":ans;
    }
};