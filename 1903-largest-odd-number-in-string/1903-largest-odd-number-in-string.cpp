class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "", curr = "";
        int i = 0, n = num.size();
        
        while (i < n){
            if ((num[i] - 48) % 2){
                if (!curr.empty()){
                    ans += curr;
                    curr.clear();
                }
                ans.push_back(num[i++]);
            }
            else{
                int j = i;
                while (j < n && (num[j] - 48) % 2 == 0){
                    curr.push_back(num[j++]);
                }
                i = j;
            }
        }
        
        return ans;
    }
};