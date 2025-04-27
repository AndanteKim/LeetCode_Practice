class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int ans = 0;
        int left = y, right = y;
        int top = x, bot = x;
        for (int r = 0; r < image.size(); ++r){
            for (int c = 0; c < image[0].size(); ++c){
                if (image[r][c] == '1'){
                    top = min(top, r);
                    bot = max(bot, r + 1);
                    left = min(left, c);
                    right = max(right, c + 1);
                }
            }
        }

        return (right - left) * (bot - top);
    }
};