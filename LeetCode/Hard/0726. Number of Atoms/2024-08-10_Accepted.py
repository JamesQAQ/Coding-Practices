class Solution:
  def countOfAtoms(self, formula: str) -> str:
    parts = self.process(formula)

    dicts = [{}]
    for i in range(0, len(parts)):
      part = parts[i]
      if part == '(':
        dicts.append({})
      elif part[0] == ')':
        num = int(part[1:]) if len(part) > 1 else 1
        for key in dicts[-1]:
          if key not in dicts[-2]:
            dicts[-2][key] = 0
          dicts[-2][key] += dicts[-1][key] * num
        dicts = dicts[:-1]
      elif part.isdigit():
        dicts[-1][parts[i - 1]] += int(part) - 1
      else:
        if part not in dicts[-1]:
          dicts[-1][part] = 0
        dicts[-1][part] += 1

    res = ''
    for key in sorted(dicts[-1].keys()):
      res += key
      if dicts[-1][key] > 1:
        res += str(dicts[-1][key])
    return res
  
  def process(self, formula: str) -> List[str]:
    res = []
    for c in formula:
      if c == '(' or c == ')':
        res.append(c)
      elif c in string.ascii_uppercase:
        res.append(c)
      elif c in string.ascii_lowercase:
        res[-1] += c
      elif res and (res[-1][-1] in string.digits or res[-1] == ')'):
        res[-1] += c
      else:
        res.append(c)
    return res