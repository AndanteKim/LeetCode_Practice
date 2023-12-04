class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "", curr;
        unordered_map<string, int> matching{{"000",0}, {"111",111},\
        {"222",222}, {"333",333}, {"444",444}, {"555",555},\
        {"666",666}, {"777",777}, {"888",888}, {"999",999}};
        int i = 0, j = 0;
        
        while (j < num.size()){
            if (j - i == 2 && num[i] == num[j]){
                curr = num.substr(i, 3);
                if (ans == "" || matching[curr] > matching[ans])
                    ans = curr;
            }
            
            if (num[i] == num[j])
                ++j;
            else
                i = j;
        }
        
        return ans;
    }
};