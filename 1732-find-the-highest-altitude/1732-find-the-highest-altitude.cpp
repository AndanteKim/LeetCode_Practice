class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int status = 0, highest = 0;
        for (const int& altitude : gain){
            status += altitude;
            highest = max(highest, status);
        }
        return highest;
    }
};