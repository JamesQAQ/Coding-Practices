class Solution:
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    
    def toGoatLatin(self, sentence: str) -> str:
        words = []
        for index, word in enumerate(sentence.split(' ')):
            if word[0] not in self.vowels:
                word = word[1:] + word[0]
            word += 'ma' + 'a' * (index + 1)
            words.append(word)
        return ' '.join(words)            
        