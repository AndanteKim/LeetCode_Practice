class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ans;
        unordered_map<int, vector<int>> rects;
        
        for (vector<int>& rectangle : rectangles){
            rects[rectangle[1]].push_back(rectangle[0]);
        }
        
        for (auto& [height, lengths] : rects){
            sort(lengths.begin(), lengths.end());
        }
        
        for (vector<int>& pt : points){
            int curr = 0;
            int x_i = pt[0], y_i = pt[1];
            
            for (auto& [height, lengths] : rects){    
                if (height >= y_i){
                    int left = 0, right = lengths.size();
                    
                    while (left < right){
                        int mid = left + (right - left) / 2;
                        if (x_i <= rects[height][mid]) right = mid;
                        else left = mid + 1;
                    }
                    curr += lengths.size() - left;
                }
            }
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};