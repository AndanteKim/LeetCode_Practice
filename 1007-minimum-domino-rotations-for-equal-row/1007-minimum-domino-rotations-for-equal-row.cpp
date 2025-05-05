class Solution {
private:
    int n;
    int check(int x, vector<int>& tops, vector<int>& bottoms){
        // How many rotations should be done
        // to have all elements in tops == x
        // and to have all ements in bottoms equal equal to x
        
        int rotationsTop = 0, rotationsBottom = 0;
        for (int i = 0; i < n; ++i){
            // rotations couldn't be done
            if (tops[i] != x && bottoms[i] != x) return -1;

            // tops[i] != x and bottoms[x] != x:
            else if (tops[i] != x)
                ++rotationsBottom;
            
            // tops[i] == x and bottoms[i] != x:
            else if (bottoms[i] != x)
                ++rotationsTop;
        }

        // min number of rotations to have all
        // elements equal to x in tops or bottoms
        return min(rotationsTop, rotationsBottom);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        this -> n = tops.size();
        int rotations = check(tops[0], tops, bottoms);

        // If one could make all elements in top or bottom equal to tops[0]
        // one could make all elements in top or bottom equal to bottoms[0]
        return (rotations != -1 || tops[0] == bottoms[0])? rotations : check(bottoms[0], tops, bottoms);
    }
};