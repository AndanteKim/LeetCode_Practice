class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numSorted(nums);
        sort(numSorted.begin(), numSorted.end());

        int currGrp = 0;
        unordered_map<int, int> numToGrp;
        numToGrp.insert(pair<int, int>(numSorted[0], currGrp));

        unordered_map<int, list<int>> grpToList;
        grpToList.insert(pair<int, list<int>>(currGrp, list<int>(1, numSorted[0])));

        for (int i = 1; i < nums.size(); ++i) {
            if (abs(numSorted[i] - numSorted[i - 1]) > limit) ++currGrp;

            numToGrp.insert(pair<int, int>(numSorted[i], currGrp));

            if (grpToList.find(currGrp) == grpToList.end()) grpToList[currGrp] = list<int>();
        
            grpToList[currGrp].push_back(numSorted[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            int grp = numToGrp[nums[i]];
            nums[i] = *grpToList[grp].begin();
            grpToList[grp].pop_front();
        }

        return nums;
    }
};