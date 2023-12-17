class Food{
public:
    string foodName;
    int foodRating;
    Food(int foodRating, string& foodName){
        this -> foodRating = foodRating;
        this -> foodName = foodName;
    }
    
    // Overload the less than operator for comparison
    bool operator<(const Food& other) const{
        // If food ratings are same sort on the basis of their name. (lexicographically smaller name food will be on top)
        if (foodRating == other.foodRating)
            return foodName > other.foodName;
        return foodRating < other.foodRating;
    }
};


class FoodRatings {
private:
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, priority_queue<Food>> cuisineFoodMap;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i){
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(rating, name)' element in current cuisine's priority queue.
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        // Update food's rating in 'foodRating' map
        foodRatingMap[food] = newRating;
        // Insert the '(new rating, name)' element in current cuisine's priority queue.
        string cuisineName = foodCuisineMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {
        // Get the highest rated 'food' of 'cuisine'.
        Food highestRated = cuisineFoodMap[cuisine].top();
        
        // If the lastest rating of 'food' doesn't match with 'rating' on which it was sorted in priority queue,
        // then we discard this element of the priority queue.
        while (foodRatingMap[highestRated.foodName] != highestRated.foodRating){
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }
        
        // return name of the highest rated 'food' of 'cuisine'
        return highestRated.foodName;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */