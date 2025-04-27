class Solution {
private:
    int top, bot;
    int left, right;

    void dfs(vector<vector<char>>& image, int r, int c){
        // Base case
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] == '0') return;

        image[r][c] = '0';
        top = min(top, r);
        bot = max(bot, r + 1);
        left = min(left, c);
        right = max(right, c + 1);

        dfs(image, r - 1 , c);
        dfs(image, r + 1, c);
        dfs(image, r, c - 1);
        dfs(image, r, c + 1);
    }


public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // Base case
        if (image.size() == 0 || image[0].size() == 0) return 0;
        
        this -> top = x; this -> bot = x;
        this -> left = y; this -> right = y;

        dfs(image, x, y);
        return (bot - top) * (right - left);    
    }
};