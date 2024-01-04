class Solution:
  def reformatDate(self, date: str) -> str:
    day, month, year = date.split(' ')
    day = day[:-2]
    return datetime.datetime.strptime(
        f'{day} {month} {year}', '%d %b %Y').strftime('%Y-%m-%d')
