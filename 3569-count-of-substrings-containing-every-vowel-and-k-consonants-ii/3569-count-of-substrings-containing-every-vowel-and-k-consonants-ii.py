class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        last_occur = {c: -1 for c in 'aeiou'}
        last_conson = deque([])
        last_last_conson = -1
        
        ans = 0

        for i, c in enumerate(word):
            if c in last_occur:
                last_occur[c] = i
            else:
                last_conson.append(i)
                if len(last_conson) == k+1:
                    last_last_conson = last_conson.popleft()
                
            if len(last_conson) == k:
                # last_last_conson <- break the substring from last consonant that pop out previously
                # min(last_occur.values()) <- get the smallest vowel occurance
                # last_conson[0] <- get the smallest consonant occurance
                ans += max(0, min(min(last_occur.values()), last_conson[0] if last_conson else len(word))-last_last_conson)
                

        
        return ans
