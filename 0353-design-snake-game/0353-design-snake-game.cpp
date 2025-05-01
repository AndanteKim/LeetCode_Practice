class SnakeGame {
private:
    int width, height;
    vector<vector<int>> food;
    unordered_map<string, pair<int, int>> movement{{"U", {-1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"D", {1, 0}}};
    unordered_set<string> snakeSet;
    deque<pair<int, int>> snake;
    int foodIndex = 0;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        /**
        * Initialize data structure
        *
        * @param width - screen width
        * @param height - screen height
        * @param food - A vector of food positions E.g. food = {{1, 1}, {1, 0}} means the first food is positioned
        *       at {1, 1}, the second is at {1, 0}.
        *
        */
        
        this -> width = width;
        this -> height = height;
        this -> food = food;
        snake.push_front({0, 0});
        snakeSet.insert(to_string(0) + " " + to_string(0));
    }

    /**
     * Moves the snake.
     *
     * @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     * @return The games score after the move. Return -1 if game over. Game over when snake crosses 
     * the screen boundary or bites its body.
     */
    int move(string direction) {
        pair<int, int> newHead = {snake.front().first + movement[direction].first, snake.front().second + movement[direction].second};

        // Boundary conditions
        bool crossesBoundary1 = newHead.first < 0 || newHead.first >= height;
        bool crossesBoundary2 = newHead.second < 0 || newHead.second >= width;

        // Checking if the snake bites itself.
        bool bitesItself = snakeSet.count(to_string(newHead.first) + " " + to_string(newHead.second)) && newHead != snake.back();

        // If any of the terminal conditions are satisfied, then we exit with rcode -1.
        if (crossesBoundary1 || crossesBoundary2 || bitesItself) return -1;

        // If there's an available food item and it's on the cell occupied by the snake after the move, eat it. 
        if (foodIndex < food.size() && newHead.first == food[foodIndex][0] && newHead.second == food[foodIndex][1]){
            ++foodIndex;    // Eat food
        }
        else{   // Not eating food: delete tail
            string tail = to_string(snake.back().first) + " " + to_string(snake.back().second);
            snakeSet.erase(tail);
            snake.pop_back();
        }

        // A new head always gets added
        snake.push_front(newHead);

        // Also add the head to the set
        snakeSet.insert(to_string(newHead.first) + " " + to_string(newHead.second));

        return snake.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */