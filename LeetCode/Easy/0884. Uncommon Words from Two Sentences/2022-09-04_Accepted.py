class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        word_set = {}
        
        def _process(s: str):
            for w in s.split(' '):
                if w not in word_set:
                    word_set[w] = 0
                word_set[w] += 1
        
        _process(s1)
        _process(s2)
        
        res = []
        for word in word_set:
            if word_set[word] == 1:
                res.append(word)
        return res
        