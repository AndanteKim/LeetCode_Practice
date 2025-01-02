class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        prefix_vowels, ans = [0] * (len(words) + 1), [0] * len(queries)
        vowels = {'a', 'e', 'i', 'o', 'u'}

        for i in range(len(words)):
            if not (words[i][0] in vowels and words[i][-1] in vowels):
                prefix_vowels[i + 1] = prefix_vowels[i]
            else:
                prefix_vowels[i + 1] = prefix_vowels[i] + 1

        for i, (left, right) in enumerate(queries):
            ans[i] = prefix_vowels[right + 1] - prefix_vowels[left]

        return ans