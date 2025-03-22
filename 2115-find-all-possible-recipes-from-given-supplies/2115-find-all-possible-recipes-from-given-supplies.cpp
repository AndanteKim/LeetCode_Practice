class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Track available ingredients and recipes
        unordered_set<string> available(supplies.begin(), supplies.end());

        // Queue to process recipe indices
        queue<int> recipeQueue;
        int lastSize = -1;
        for (int i = 0; i < recipes.size(); ++i) recipeQueue.push(i);

        // Continue while we keep finding new recipes
        vector<string> createdRecipes;
        while (static_cast<int> (available.size()) > lastSize){
            lastSize = available.size();
            int queueSize = recipeQueue.size();

            // Process all recipes in current queue
            while (queueSize > 0){
                bool canCreate = true;
                --queueSize;
                int recipeIndex = recipeQueue.front(); recipeQueue.pop();

                // Check if all ingredients are available
                for (const string& ingredient : ingredients[recipeIndex]){
                    if (!available.count(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }
                
                if (canCreate){
                    // Recipe can be created - add to available items
                    available.insert(recipes[recipeIndex]);
                    createdRecipes.push_back(recipes[recipeIndex]);
                }
                else
                    recipeQueue.push(recipeIndex);
            }
        }

        return createdRecipes;
    }
};