class Solution:
  def isAlienSorted(self, words: List[str], order: str) -> bool:
    mapping = {}
    ascii_value = 97
    for char in order:
      mapping[char] = chr(ascii_value)
      ascii_value += 1
    alien_words = []
    for word in words:
      alien_words.append(''.join(mapping[char] for char in word))
    return alien_words == sorted(alien_words)
