SELECT a.`hacker_id`, b.`name`, SUM(a.`score`) AS `score`
FROM (SELECT `hacker_id`, MAX(`score`) AS `score`
      FROM `Submissions`
      GROUP BY `hacker_id`, `challenge_id`) a,
     `Hackers` b
WHERE a.`hacker_id` = b.`hacker_id`
AND `score` > 0
GROUP BY a.`hacker_id`
ORDER BY `score` DESC, a.`hacker_id`;