class FoodRatings {
private:
    // Map food with its raating
    unordered_map<string, int> foodRatingMap;
    // Map food with the cuisine it belongs to
    unordered_map<string, string> foodCuisineMap;
    
    // Store all food of cuisine in set (to sort them on ratings/name)
    // Set element -> Pair: (-1 * foodRating, foodName)
    map<string, set<pair<int, string>>> cuisineFoodMap;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i){
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(-1 * rating, name)' element in current cuisine's set.
            cuisineFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // Fetch cuisine name for food
        string cuisineName = foodCuisineMap[food];
        
        // Find and delete the element from the respective cuisine's set
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({-foodRatingMap[food], food});
        cuisineFoodMap[cuisineName].erase(oldElementIterator);
        
        // Update food's rating in 'foodRating' map
        foodRatingMap[food] = newRating;
        
        // Insert the '(-1 * new rating, name)' element in respective cuisine' set
        cuisineFoodMap[cuisineName].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // Return name of the highest rated 'food' of 'cuisine'
        return cuisineFoodMap[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */