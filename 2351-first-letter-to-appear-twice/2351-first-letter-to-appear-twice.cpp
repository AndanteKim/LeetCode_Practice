class Solution {
public:
    char repeatedCharacter(string s) {
        set<int> lookup;
        for (const auto c: s){
            if (lookup.find(c) != lookup.end()) return c;
            lookup.insert(c);
        }
        return '\0';
    }
};