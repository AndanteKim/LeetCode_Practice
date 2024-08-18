class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        word_key = "$"
        trie = dict()
        
        for word in words:
            node = trie
            for letter in word:
                # Retrieve the next node; If not found, create a empty node.
                node = node.setdefault(letter, {})
                
            # Mark the existence of a word in trie node
            node[word_key] = word
            
        rows, cols = len(board), len(board[0])
        
        ans = []
        
        def backtrack(row: int, col: int, parent: Dict[chr, Union[chr, str]]) -> None:
            letter = board[row][col]
            curr_node = parent[letter]
            
            # Check if we find a match of word
            word_match = curr_node.pop(word_key, False)
            if word_match:
                # Also we removed the matched word to avoid duplicates,
                # as well as avoiding using set() for results.
                ans.append(word_match)
                
            # Before the exploration, mark the cell as visited
            board[row][col] = "#"
            
            # Explore the neighbors in 4 directions, i.e. up, down, left, right
            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                new_r, new_c = row + dr, col + dc
                if new_r < 0 or new_r >= rows or new_c < 0 or new_c >= cols:
                    continue
                
                if not board[new_r][new_c] in curr_node:
                    continue
                    
                backtrack(new_r, new_c, curr_node)
                
            # End of exploration, we restore the cell
            board[row][col] = letter
            
            # Optimization: incrementally remove the matched leaf node in Trie.
            if not curr_node:
                parent.pop(letter)
                
        for row in range(rows):
            for col in range(cols):
                # Starting from each of the cells
                if board[row][col] in trie:
                    backtrack(row, col, trie)
                    
        return ans