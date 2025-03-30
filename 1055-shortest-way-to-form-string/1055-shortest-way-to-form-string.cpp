class Solution {
private:
    // To check if toCheck is a substring of inString
    bool isSubsequence(string& toCheck, string& inString){
        int i = 0, j = 0;

        while (i < toCheck.size() && j < inString.size()){
            if (toCheck[i] == inString[j])
                ++i;
            ++j;
        }

        return i == toCheck.size();
    }

public:
    int shortestWay(string source, string target) {
        unordered_set<char> sourceChars(source.begin(), source.end());

        // Check if all characters of the target are present in the source
        // If any charactr is not present, return -1
        for (const char& t : target){
            if (!sourceChars.count(t)) return -1;
        }
        
        // Concatenate source until the target is a subsequence of the concatenated string
        string sourceSubsequence = source;
        int ans = 1;
        while (!isSubsequence(target, sourceSubsequence)){
            sourceSubsequence += source;
            ++ans;
        }

        // Number of concatenations done
        return ans;
    }
};