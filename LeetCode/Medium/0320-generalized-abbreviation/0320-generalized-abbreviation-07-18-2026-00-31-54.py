class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        n, ans = len(word), []

        for mask in range(1 << n):
            curr_word, abbr_cnt = [], 0

            for i in range(n):
                # If the bit at the position index is 1, increment the abbreviated substring.
                if mask & (1 << i):
                    abbr_cnt += 1
                else:
                    if abbr_cnt > 0:
                        curr_word.append(str(abbr_cnt))
                        abbr_cnt = 0
                    curr_word.append(word[i])
            
            if abbr_cnt > 0:
                curr_word.append(str(abbr_cnt))
            ans.append("".join(curr_word))
        
        return ans