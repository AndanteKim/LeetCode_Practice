class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        
        // Create a map to store height-name pairs
        map<int, string> heightToNames;
        for (int i = 0; i < n; ++i)
            heightToNames[heights[i]] = names[i];
        
        // Populate the map with height asa key and name as value
        sort(heights.begin(), heights.end(), [](int a, int b){return a > b;});
        
        vector<string> ans;
        
        // Populate sorted_names vector in descending order of height
        for (int h : heights)
            ans.push_back(heightToNames[h]);
        
        return ans;
    }
};