class Robot {
private:
    unordered_map<int, string> TO_DIR {{0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};
    bool moved = false;
    int idx;
    vector<vector<int>> pos;
    vector<int> dirs;

public:
    Robot(int width, int height) {
        idx = 0;

        for (int i = 0; i < width; ++i) {
            pos.push_back({i, 0});
            dirs.push_back(0);
        }

        for (int i = 1; i < height; ++i) {
            pos.push_back({width - 1, i});
            dirs.push_back(1);
        }

        for (int i = width - 2; i >= 0; --i) {
            pos.push_back({i, height - 1});
            dirs.push_back(2);
        }

        for (int i = height - 2; i >= 1; --i) {
            pos.push_back({0, i});
            dirs.push_back(3);
        }
        dirs[0] = 3;
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return pos[idx];
    }
    
    string getDir() {
        if (!moved) return "East";
        return TO_DIR[dirs[idx]];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */