class Solution:
  def reorderSpaces(self, text: str) -> str:
    space = 0
    for c in text:
      if c == ' ':
        space += 1
    splits = text.split(' ')
    words = []
    for part in splits:
      if part:
        words.append(part)
    remain = space % (len(words) - 1) if len(words) > 1 else space
    num = space // (len(words) - 1) if len(words) > 1 else 0
    return (' ' * num).join(words) + ' ' * remain
