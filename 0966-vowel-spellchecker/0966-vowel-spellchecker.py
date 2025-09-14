class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def devowel(word: str) -> str:
            return "".join('*' if c in "aeiou" else c for c in word)
        
        def solve(query: str) -> str:
            if query in words_perfect:
                return query
            
            query_l = query.lower()
            if query_l in words_cap:
                return words_cap[query_l]
            
            query_lv = devowel(query_l)
            if query_lv in words_vow:
                return words_vow[query_lv]
            return ""

        words_perfect = set(wordlist)
        words_cap, words_vow = dict(), dict()

        for word in wordlist:
            word_low = word.lower()
            words_cap.setdefault(word_low, word)
            words_vow.setdefault(devowel(word_low), word)

        return list(map(solve, queries))