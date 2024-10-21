class Solution {
private:
    int n;
    int backtrack(int i, string curr, string& s, unordered_set<string>& seen){
        // Base case: If i reaches at the end of string
        if (i == n) return seen.size();
        int maximumSplit = 0;
        curr.push_back(s[i]);
        if (!seen.count(curr)){
            seen.insert(curr);
            maximumSplit = backtrack(i + 1, "", s, seen);
            seen.erase(curr);
        }
        maximumSplit = max(maximumSplit, backtrack(i + 1, curr, s, seen));
        return maximumSplit;
    }
    
public:
    int maxUniqueSplit(string s) {
        this -> n = s.size();
        unordered_set<string> seen;
        return backtrack(0, "", s, seen);
    }
};