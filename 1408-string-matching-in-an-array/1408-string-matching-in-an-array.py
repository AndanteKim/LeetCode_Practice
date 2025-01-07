class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words.sort(key = lambda x: len(x), reverse = True)
        ans, seen = set(), set()

        for sub_word in words:
            for word in seen:
                if sub_word in word:
                    ans.add(sub_word)
            seen.add(sub_word)

        return list(ans)
