class Solution:
    def removeVowels(self, S: str) -> str:
        return "".join([c for c in S if not c in "aeiou"])
        