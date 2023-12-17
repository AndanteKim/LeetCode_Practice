class Food:
    def __init__(self, food_rating: List[str], food_name: List[str]):
        self.food_rating, self.food_name = food_rating, food_name
    
    def __lt__(self, other: 'Food') -> bool:
        # Overload the less than than operator for comparison
        # If food ratings are the same, sort based on their name (lexicographically smaller name food will be on top).
        if self.food_rating == other.food_rating:
            return self.food_name < other.food_name
        
        # Sort based on food rating (bigger rating food will be on top).
        return self.food_rating > other.food_rating

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # Map food with its rating, the cuisine it belongs to.
        self.food_rating_map, self.food_cuisine_map = dict(), dict()
        
        # Store all food of a cuisine in a priority queue (to sort them on ratings/name)
        # Priority queue element -> Food: (food_rating, food_name)
        self.cuisine_food_map = defaultdict(list)
        
        for i in range(len(foods)):
            # Store 'rating' and 'cuisine' of the current 'food' in 'food_rating_map' and 'food_cuisine_map' maps
            self.food_rating_map[foods[i]], self.food_cuisine_map[foods[i]] = ratings[i], cuisines[i]
            
            # Insert the '(rating, name)' element into the current cuisine's priority queue
            heappush(self.cuisine_food_map[cuisines[i]], Food(ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        # Update food's rating in 'food_rating' map
        self.food_rating_map[food] = newRating
        
        # Insert the '(new rating, name)' element in the respective cuisine's priority queue
        cuisine_name = self.food_cuisine_map[food]
        heappush(self.cuisine_food_map[cuisine_name], Food(newRating, food))

    def highestRated(self, cuisine: str) -> str:
        # Get the highest rated 'food' of 'cuisine'
        highest_rated = self.cuisine_food_map[cuisine][0]
        
        # If the lastest rating of 'food' doesn't match with the 'rating' on which it was sorted in the priority queue,
        # then we discaard this element from the priority queue
        while self.food_rating_map[highest_rated.food_name] != highest_rated.food_rating:
            heappop(self.cuisine_food_map[cuisine])
            highest_rated = self.cuisine_food_map[cuisine][0]
            
        # Return the name of the highest-rated 'food' of 'cuisine'.
        return highest_rated.food_name


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)