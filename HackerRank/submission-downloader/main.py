import argparse
import json
import logging
import requests
import os
import sys

import cookie


HEADERS = {
    'Accept': '*/*',
    'Accept-Encoding': 'identity',
    'Cookie': cookie.COOKIE,
    'User-Agent': 'Chrome/120.0.0.0',
}
EXTENSION = {
  'mysql': 'sql',
}

if __name__ == '__main__':
  logging.basicConfig(
      stream=sys.stdout,
      level=logging.INFO,
      format='[%(levelname)s] %(asctime)s - %(message)s',
      datefmt='%H:%M:%S')

  parser = argparse.ArgumentParser()
  parser.add_argument('-o', '--output-dir', type=str)
  parser.add_argument('-c', '--code-url', type=str)
  args = parser.parse_args()

  if args.output_dir and args.code_url:
    rest_url = args.code_url.replace(
        'challenges', 'rest/contests/master/challenges')
    rest_url = rest_url.replace('submissions/code', 'submissions')
    response = json.loads(requests.get(rest_url, headers=HEADERS).text)['model']

    prepare_name = response['name'].strip()
    os.makedirs(args.output_dir, exist_ok=True)
    os.makedirs(os.path.join(args.output_dir, prepare_name), exist_ok=True)

    date_str = response['created_at'].split('T')[0]
    extension_name = EXTENSION[response['language']]
    filename = f'{date_str}_Accepted.{extension_name}'
    with open(os.path.join(args.output_dir, prepare_name, filename), 'w') as f:
      f.write(response['code'])
