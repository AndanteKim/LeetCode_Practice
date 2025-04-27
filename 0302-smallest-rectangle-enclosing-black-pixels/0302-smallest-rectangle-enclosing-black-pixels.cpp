class Solution {
private:
    int searchColumns(vector<vector<char>>& image, int i, int j, int top, int bottom, bool white2black){
        while (i != j){
            int k = top, mid = (i + j) >> 1;

            while (k < bottom && image[k][mid] == '0') ++k;

            if (k < bottom == white2black)  // k < bottom means the column mid has black pixel
                j = mid;    // search the boundary in the smaller half
            else
                i = mid + 1;    // search the boundary in the greater half
        }

        return i;
    }

    int searchRows(vector<vector<char>>& image, int i, int j, int left, int right, bool white2black){
        while (i != j){
            int k = left, mid = (i + j) >> 1;

            while (k < right && image[mid][k] == '0') ++k;

            if (k < right == white2black) j = mid;  // k < right means the row mid has black pixel
            else
                i = mid + 1;
        }

        return i;
    }

public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = searchColumns(image, 0, y, 0, m, true);
        int right = searchColumns(image, y + 1, n, 0, m, false);
        int top = searchRows(image, 0, x, left, right, true);
        int bottom = searchRows(image, x + 1, m, left, right, false);
        
        return (right - left) * (bottom - top);
    }
};