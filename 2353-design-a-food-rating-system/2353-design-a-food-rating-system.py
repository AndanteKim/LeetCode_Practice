class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_data, self.cuisine_data = dict(), defaultdict(SortedList)
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_data[food] = (cuisine, rating)
            self.cuisine_data[cuisine].add((-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.food_data[food]
        self.food_data[food] = cuisine, newRating
        self.cuisine_data[cuisine].remove((-rating, food))
        self.cuisine_data[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.cuisine_data[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)