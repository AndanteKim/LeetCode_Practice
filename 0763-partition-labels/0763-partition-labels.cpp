class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> firstOccurrence(26, -1), lastOccurrence(26);

        // Store the last occurrence index of each character
        for (int i = 0; i < n; ++i){
            lastOccurrence[s[i] - 97] = i;
        }

        vector<int> ans;
        int partitionStart = 0, partitionEnd = 0;
        
        for (int i = 0; i < n; ++i){
            // Store the first occurrence index of each character (if not set)
            if (firstOccurrence[s[i] - 97] == -1)
                firstOccurrence[s[i] - 97] = i;

            // If we find a new partition start
            if (partitionEnd < firstOccurrence[s[i] - 97]){
                ans.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i; partitionEnd = i;
            }

            // Update partition end boundary
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 97]);
        }

        // Add the last partition if it exists
        if (partitionEnd - partitionStart + 1 > 0)
            ans.push_back(partitionEnd - partitionStart + 1);

        return ans;
    }
};