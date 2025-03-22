class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        # Track available ingredients and recipes
        available = {supply for supply in supplies}
        
        # Queue to process recipe indices
        recipe_queue = deque(range(len(recipes)))
        created_recipes, last_size = [], -1

        # Continue while we keep finding new recipes
        while len(available) > last_size:
            last_size, queue_sz = len(available), len(recipe_queue)

            # Process all recipes in current queue
            while queue_sz > 0:
                queue_sz -= 1
                recipe_idx = recipe_queue.popleft()
                if all(ingredient in available for ingredient in ingredients[recipe_idx]):
                    # Recipe can be created - add to available items
                    available.add(recipes[recipe_idx])
                    created_recipes.append(recipes[recipe_idx])
                else:
                    recipe_queue.append(recipe_idx)
        
        return created_recipes

