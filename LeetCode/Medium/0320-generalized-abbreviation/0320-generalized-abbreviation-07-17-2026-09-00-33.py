class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        def backtrack(curr_word: str, i: int, abbr_cnt: int) -> None:
            if i == n:
                if abbr_cnt > 0:
                    curr_word += str(abbr_cnt)
                ans.append(curr_word)
                return

            # Keep the current character
            backtrack(curr_word + (str(abbr_cnt) if abbr_cnt > 0 else "") + word[i], i + 1, 0)

            # Abbreviate the current character
            backtrack(curr_word, i + 1, abbr_cnt + 1)
        
        ans, n = [], len(word)
        backtrack("", 0, 0)

        return ans