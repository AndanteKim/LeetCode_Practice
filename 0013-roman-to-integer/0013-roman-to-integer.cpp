class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mapping{
            {"I",1}, {"II",2}, {"III",3}, {"IV",4}, {"V",5},
            {"VI",6}, {"VII",7}, {"VIII",8}, {"IX",9}, {"X",10},
            {"XL",40}, {"L",50}, {"XC",90}, {"C",100}, {"CD",400},
            {"D",500}, {"CM",900}, {"M",1000}
        };
        
        int i = 0, n = s.size(), ans = 0;
        string curr = "";
        while (i < n){
            if (!mapping.count(curr + s[i])){
                ans += mapping[curr];
                curr.clear();
            }
            curr.push_back(s[i]);
            ++i;
        }
        if (!curr.empty()){
            ans += mapping[curr];
        }
        
        return ans;
    }
};