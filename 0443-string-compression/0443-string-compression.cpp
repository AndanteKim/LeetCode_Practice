class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0, group_length;
        while (i < chars.size()){
            group_length = 1;
            while (i + group_length < chars.size() && chars[i + group_length] == chars[i])
                ++group_length;
            chars[res++] = chars[i];
            if (group_length > 1){
                for (char& c : to_string(group_length)){
                    chars[res++] = c;
                }
            }
            i += group_length;
        }
        
        return res;
    }
};