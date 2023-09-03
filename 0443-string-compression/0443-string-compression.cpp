class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ans = 0, n = chars.size();
        
        while (i < n){
            int groupLength = 1;
            while (i + groupLength < n && chars[i + groupLength] == chars[i]) ++groupLength;
            chars[ans++] = chars[i];
            if (groupLength > 1){
                for (char& c : to_string(groupLength)) chars[ans++] = c;
            }
            i += groupLength;
        }
        
        return ans;
    }
};