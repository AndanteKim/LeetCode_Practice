class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> freqs;
        int maxFreq = 0;
        // store the frequency and find the highest frequency
        for (char& c : s){
            ++freqs[c];
            maxFreq = max(maxFreq, freqs[c]);
        }
        unordered_set<char> mostChars, secondChars;
        // store all the characters with the highest and second highest frequency - 1
        for (auto&[c, freq] : freqs){
            if (freq == maxFreq) mostChars.insert(c);
            else if (freq == maxFreq - 1) secondChars.insert(c);
        }
        
        // create maxFreq number of different strings
        string segments[maxFreq];
        // insert one instance of characters with frequency maxFreq & maxFreq - 1 in each segment
        for (int i = 0; i < maxFreq; ++i){
            for (const char& c1 : mostChars) segments[i] += c1;
            // skip the last segment as the frequency is only maxFreq - 1
            if (i < maxFreq - 1){
                for (const char& c2 : secondChars) segments[i] += c2;
            }
        }
        
        int segmentId = 0;
        // Iterate over the remaining characters, and for each, distribute the instances over the segments
        for (auto& [currChar, _] : freqs){
            // skip characters with maxFreq or maxFreq - 1
            // frequency as they have already been inserted
            if (mostChars.find(currChar) != mostChars.end() || secondChars.find(currChar) != secondChars.end()) continue;
            
            // distribute the instances of these characters over the segments in a round-robin manner
            for (int freq = freqs[currChar]; freq > 0; --freq){
                segments[segmentId] += currChar;
                segmentId = (segmentId + 1) % (maxFreq - 1);
            }
        }
        
        // each segment except the last should have exactly k elements; else, return ""
        for (int i = 0; i < maxFreq - 1; ++i){
            if (segments[i].size() < k) return "";
        }
        
        string ans;
        // Join all the segments and return them
        for (string& s : segments) ans += s;
        return ans;
    }
};