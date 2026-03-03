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


GRAPHQL_URL = 'https://leetcode.com/graphql/'
HEADERS = {
    'Accept': '*/*',
    'Accept-Encoding': 'identity',
    'Content-Type': 'application/json',
    'Cookie': cookie.COOKIE,
}
EXTENSION_NAME = {
  'cpp': 'cpp',
  'python3': 'py',
  'mysql': 'sql',
}


class QuestionStatus(enum.Enum):
  SOLVED = 1


class SubmissionStatus(enum.Enum):
  ACCEPTED = 10


@dataclass
class Question:
  frontendId: str
  title: str
  titleSlug: str
  difficulty: str
  numSubmitted: int
  questionStatus: str


@dataclass
class Submission:
  id: str
  status: int


@dataclass
class SubmissionDetails:
  code: str
  timestamp: int
  statusCode: int
  langName: str
  titleSlug: str


class LeetCodeCrawlerV2:

  def GetUserProgressQuestionList(
      self, limit: int, skip: int) -> List[Question]:
    operationName = 'userProgressQuestionList'
    data = {
      'operationName': operationName,
      'query': open(os.path.join('query', operationName)).read(),
      'variables': {
        'filters': {
          'limit': limit,
          'skip': skip,
          'sortField': 'LAST_SUBMITTED_AT',
          'sortOrder': 'DESCENDING',
        },
      },
    }
    graphql_result = json.loads(self._CallGraphql(data))

    questions = []
    for question in graphql_result['data'][operationName]['questions']:
      questions.append(
          Question(
              frontendId=question['frontendId'],
              title=question['title'],
              titleSlug=question['titleSlug'],
              difficulty=question['difficulty'],
              numSubmitted=question['numSubmitted'],
              questionStatus=question['questionStatus']))
    return questions

  def GetUserProgressSubmissionList(
      self, question: Question) -> List[Submission]:
    operationName = 'userProgressSubmissionList'
    data = {
      'operationName': operationName,
      'query': open(os.path.join('query', operationName)).read(),
      'variables': {
        'limit': question.numSubmitted,
        'offset': 0,
        'questionSlug': question.titleSlug,
      },
    }
    graphql_result = json.loads(self._CallGraphql(data))

    submissions = []
    for submission in graphql_result['data'][operationName]['submissions']:
      submissions.append(
          Submission(
              id=submission['id'],
              status=submission['status']))
    return submissions

  def GetSubmissionDetails(self, submission_id: int) -> SubmissionDetails:
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
    return SubmissionDetails(
        code=submissionDetails['code'],
        timestamp=submissionDetails['timestamp'],
        statusCode=submissionDetails['statusCode'],
        langName=EXTENSION_NAME[submissionDetails['lang']['name']],
        titleSlug=submissionDetails['question']['titleSlug'])

  def _CallGraphql(self, data: dict) -> str:
    response = requests.post(GRAPHQL_URL, headers=HEADERS, json=data)
    if response.status_code == 200:
      return response.text


def Main(args: argparse.Namespace):
  if not args.output_dir:
    return

  os.makedirs(args.output_dir, exist_ok=True)
  crawler = LeetCodeCrawlerV2()

  limit = args.limit if args.limit else 1
  offset = 0
  while offset < limit:
    limit = min(limit - offset, 50)
    for question in crawler.GetUserProgressQuestionList(limit, offset):
      if question.questionStatus == QuestionStatus.SOLVED.name:
        for submission in crawler.GetUserProgressSubmissionList(question):
          if submission.status == SubmissionStatus.ACCEPTED.value:
            question_dir = os.path.join(
                args.output_dir,
                question.difficulty.capitalize(),
                f'{int(question.frontendId):04d}. {question.title}',
            ).replace('?', '？').strip()
            os.makedirs(question_dir, exist_ok=True)

            submission_details = crawler.GetSubmissionDetails(submission.id)
            date_str = datetime.fromtimestamp(
                submission_details.timestamp).strftime('%Y-%m-%d')
            file_path = os.path.join(
                question_dir,
                f'{date_str}_Accepted.{submission_details.langName}')

            count = 1
            while os.path.exists(file_path):
              count += 1
              file_path = os.path.join(
                  question_dir,
                  f'{date_str}_{count}_Accepted.{submission_details.langName}')
            with open(file_path, 'w') as f:
              f.write(submission_details.code)
              logging.info(f'{file_path} is downloaded.')
            sleep(2)  # Download slowly.
    offset += 50


if __name__ == '__main__':
  logging.basicConfig(
      stream=sys.stdout,
      level=logging.INFO,
      format='[%(levelname)s] %(asctime)s - %(message)s',
      datefmt='%H:%M:%S')

  parser = argparse.ArgumentParser()
  parser.add_argument('-o', '--output-dir', type=str)
  parser.add_argument('-l', '--limit', type=int)
  Main(parser.parse_args())
