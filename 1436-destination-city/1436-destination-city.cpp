class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> lookup;
        for (const vector<string>&path : paths) lookup[path[0]] = path[1];
        string current_loc = paths[0][0];
        while (lookup.find(current_loc) != lookup.end()) current_loc = lookup[current_loc];
        return current_loc;
    }
};