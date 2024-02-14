class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string sample = "123456789";
        int n = 10, lowSz = to_string(low).size(), highSz = to_string(high).size();
        vector<int> ans;
        
        
        for (int length = lowSz; length <= highSz; ++length){
            for (int start = 0; start < n - length; ++start){
                int num = stoi(sample.substr(start, length));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        
        return ans;
    }
};