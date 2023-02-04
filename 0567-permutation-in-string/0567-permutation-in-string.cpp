class Solution {
    
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2) return false;
        
        vector<int> dic_s1(26, 0), dic_s2(26, 0);
        
        for (int i = 0; i < l1; ++i) {
            ++dic_s1[s1[i] - 'a'];
            ++dic_s2[s2[i] - 'a'];
        }
        
        int cnt = 0;
        for (int i = 0; i < 26; ++i) if (dic_s1[i] == dic_s2[i]) ++cnt; 
        
        for (int i = 0; i < l2 - l1; ++i){
            int right = s2[i + l1] - 'a', left = s2[i] - 'a';
            if (cnt == 26) return true;
            ++dic_s2[right];
            if (dic_s2[right] == dic_s1[right]) ++cnt;
            else if (dic_s2[right] == dic_s1[right] + 1) --cnt;
            
            --dic_s2[left];
            if (dic_s2[left] == dic_s1[left]) ++cnt;
            else if (dic_s2[left] == dic_s1[left] - 1) --cnt;
        }
        
        return cnt == 26;
    }
};