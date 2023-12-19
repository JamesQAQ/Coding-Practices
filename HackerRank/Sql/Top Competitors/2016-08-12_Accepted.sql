SELECT hacker_id, name
FROM
(SELECT hacker_id, name, count(*) as cnt
FROM (SELECT a.hacker_id, a.name
FROM Hackers as a, Difficulty as b, Challenges as c, Submissions as d
WHERE a.hacker_id = d.hacker_id
AND c.difficulty_level = b.difficulty_level
AND d.score = b.score
AND c.challenge_id = d.challenge_id
GROUP BY a.hacker_id, c.challenge_id) as tmp
GROUP BY hacker_id) as res
WHERE cnt > 1
ORDER BY cnt DESC, hacker_id;