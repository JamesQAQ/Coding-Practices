import argparse
import html
import json
import logging
import os
import sys
from time import sleep

from bs4 import BeautifulSoup
import requests

import cookie


URL = 'https://zerojudge.tw/'
HEADERS = {
    'Accept': '*/*',
    'Accept-Encoding': 'identity',
    'Cookie': 'JSESSIONID=' + cookie.JSESSIONID,
    'User-Agent': 'Chrome/136.0.0.0',
}
EXTENSION_NAME = {
  'C': 'c',
  'CPP': 'cpp',
  'PYTHON': 'py',
  'JAVA': 'java',
}
REPLACE_MAP = {
  '?': '？',
  ':': '：',
  '*': '＊',
  '"': '＂',
  '<': '＜',
  '>': '＞',
  '|': '｜',
  '/': '／',
  '\\': '＼',
}


def get_solution(solution_id: str):
  url = f'{URL}Solution.json?data=Code&solutionid={solution_id}'
  response = json.loads(requests.get(url, headers=HEADERS).text)
  logging.info('Solution ID %s was downloaded.', solution_id)
  return html.unescape(response['code']).replace('\r\n', '\n')


def replace_with_fullwidth(s: str):
  result = ''.join(REPLACE_MAP.get(c, c) for c in s)
  return result.replace('...', '⋯')


if __name__ == '__main__':
  logging.basicConfig(
      stream=sys.stdout,
      level=logging.INFO,
      format='[%(levelname)s] %(asctime)s - %(message)s',
      datefmt='%H:%M:%S')

  parser = argparse.ArgumentParser()
  parser.add_argument('-a', '--account', type=str)
  parser.add_argument('-o', '--output-dir', type=str)
  parser.add_argument('-m', '--max-page-id', type=int)
  args = parser.parse_args()

  if args.account and args.output_dir and args.max_page_id:
    os.makedirs(args.output_dir, exist_ok=True)

    for page_id in range(1, args.max_page_id + 1):
      url = f'{URL}Submissions?account={args.account}&page={page_id}'
      soup = BeautifulSoup(requests.get(url, headers=HEADERS).text, 'html.parser')
      for tr in soup.find_all('tr', attrs={'solutionid': True}):
        solution_id = tr.get('solutionid')
        tds = tr.find_all('td')
        title = tds[2].text.split('--')[0].strip()
        status = tds[3].find('a', attrs={'data-solutionid': True}).text
        code_type = tds[4].find('button', attrs={'data-solutionid': True}).text
        date = tds[5].text.strip().split(' ')[0]

        if status == 'AC':
          dir_path = os.path.join(
              args.output_dir, replace_with_fullwidth(title))
          os.makedirs(dir_path, exist_ok=True)
          filename = f'{date}_{solution_id}.{EXTENSION_NAME[code_type]}'
          path = os.path.join(dir_path, filename)
          if not os.path.exists(path):
            with open(path, 'wb') as f:
              f.write(get_solution(solution_id).encode('utf-8'))
            logging.info('File path %s was saved.', path)
            sleep(2)
