class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        unordered_map<char, int> countType;
        for (string& dummy : garbage){
            for (char& trashType : dummy){
                ++countType[trashType];
            }
        }
        
        for (auto& [truck, _] : countType){
            int curr = 0;
            for (int i = 0; i < garbage.size(); ++i){
                for (char& trash : garbage[i]){
                    if (trash == truck){
                        ++curr;
                        --countType[trash];
                    }
                }
                if (!countType[truck])
                    break;
                if (i < travel.size())
                    curr += travel[i];
            }
            time += curr;
        }
        
        return time;
    }
};