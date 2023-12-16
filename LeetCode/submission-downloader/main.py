import abc
import argparse
from dataclasses import dataclass
from datetime import datetime
import enum
import json
import logging
import os
import sys
from time import sleep
from typing import List

import requests

import cookie


URL = 'https://leetcode.com/graphql/'
HEADERS = {
    'Accept': '*/*',
    'Accept-Encoding': 'identity',
    'Content-Type': 'application/json',
    'Cookie': cookie.COOKIE,
}
LIMIT_MAX = 9999


class ProblemStatus(enum.Enum):
  NOT_STARTED = 1
  AC = 2
  TRIED = 3



class ProblemDifficulty(enum.Enum):
  EASY = 1
  MEDIUM = 2
  HARD = 3


class SubmissionStatus(enum.Enum):
  ACCEPTED = 10
  WRONG_ANSWER = 11
  MEMORY_LIMIT_EXCEEDED = 12
  OUTPUT_LIMIT_EXCEEDED = 13
  TIME_LIMIT_EXCEEDED = 14
  RUNTIME_ERROR = 15
  INTERNAL_ERROR = 16
  COMPLIE_ERROR = 20
  TIMEOUT = 30


@dataclass
class Problem:
  frontendQuestionId: str
  title: str
  title_slug: str


@dataclass
class Submission:
  code: str
  timestamp: int
  lang_name: str


class LeetCodeCrawler:

  def GetProblemList(
      self,
      status: ProblemStatus,
      difficulty: ProblemDifficulty,
      limit: int = LIMIT_MAX) -> List[Problem]:
    operationName = 'problemsetQuestionList'
    data = {
      'operationName': operationName,
      'query': open(os.path.join('query', operationName)).read(),
      'variables': {
        'categorySlug': 'all-code-essentials',
        'limit': limit,
        'filters': {
          'status': status.name,
          'difficulty': difficulty.name,
        }
      },
    }
    graphql_result = json.loads(self._CallGraphql(data))

    result = []
    for question in graphql_result['data'][operationName]['questions']:
      result.append(
          Problem(
              frontendQuestionId=question['frontendQuestionId'],
              title=question['title'],
              title_slug=question['titleSlug']))
    return result

  def GetSubmissionIdList(
      self,
      questionSlug: str,
      status: SubmissionStatus,
      limit: int = LIMIT_MAX) -> List[int]:
    operationName = 'submissionList'
    data = {
      'operationName': operationName,
      'query': open(os.path.join('query', operationName)).read(),
      'variables': {
        'offset': 0,
        'limit': limit,
        'questionSlug': questionSlug,
        'status': status.value,
      },
    }
    graphql_result = json.loads(self._CallGraphql(data))

    submissions = graphql_result[
        'data']['questionSubmissionList']['submissions']
    result = [int(submission['id']) for submission in submissions]
    return result

  def GetSubmission(self, submission_id: int) -> Submission:
    operationName = 'submissionDetails'
    data = {
      'operationName': operationName,
      'query': open(os.path.join('query', operationName)).read(),
      'variables': {
        'submissionId': submission_id,
      },
    }
    graphql_result = json.loads(self._CallGraphql(data))

    submissionDetails = graphql_result['data'][operationName]
    return Submission(
        code=submissionDetails['code'],
        timestamp=submissionDetails['timestamp'],
        lang_name=submissionDetails['lang']['name'])

  def _CallGraphql(self, data: dict) -> str:
    response = requests.post(URL, headers=HEADERS, json=data)
    if response.status_code == 200:
      return response.text


def Main(args: argparse.Namespace):
  if not args.output_dir:
    return

  os.makedirs(args.output_dir, exist_ok=True)
  crawler = LeetCodeCrawler()

  for difficulty in ProblemDifficulty:
    for problem in crawler.GetProblemList(ProblemStatus.AC, difficulty):
      problem_dirname = (
          f'{int(problem.frontendQuestionId):04d}. {problem.title}')
      problem_dir = os.path.join(
          args.output_dir, difficulty.name.capitalize(), problem_dirname)
      os.makedirs(problem_dir, exist_ok=True)

      submission_id_list = crawler.GetSubmissionIdList(
          problem.title_slug, SubmissionStatus.ACCEPTED)

      date_str_count = {}
      for submission_id in submission_id_list:
        submission = crawler.GetSubmission(submission_id)
        date_str = datetime.fromtimestamp(
            submission.timestamp).strftime('%Y-%m-%d')
        suffix = ''
        if date_str not in date_str_count:
          date_str_count[date_str] = 1
        else:
          date_str_count[date_str] += 1
          suffix = f'_{date_str_count[date_str]}'
        filename = f'{date_str}{suffix}_Accepted.{submission.lang_name}'
        file_path = os.path.join(problem_dir, filename)
        with open(file_path, 'w') as f:
          f.write(submission.code)
          logging.info(f'{file_path} is downloaded.')

        sleep(10)  # Download slowly.


if __name__ == '__main__':
  logging.basicConfig(
      stream=sys.stdout,
      level=logging.INFO,
      format='[%(levelname)s] %(asctime)s - %(message)s',
      datefmt='%H:%M:%S')

  parser = argparse.ArgumentParser()
  parser.add_argument('-o', '--output-dir', type=str)
  Main(parser.parse_args())
