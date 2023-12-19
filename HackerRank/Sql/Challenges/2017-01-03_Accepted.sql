SELECT a.`hacker_id`, c.`name`, a.`count`
FROM (SELECT `hacker_id`, COUNT(*) AS `count`
      FROM `Challenges`
      GROUP BY `hacker_id`) a,
     (SELECT `count`, COUNT(`count`) as `count_count`
      FROM (SELECT `hacker_id`, COUNT(*) AS `count`
            FROM `Challenges`
            GROUP BY `hacker_id`
            ) AS tmp
      GROUP BY `count`) b,
      `Hackers` c
WHERE (a.`count` = (SELECT MAX(`count`)
                   FROM (SELECT `hacker_id`, COUNT(*) AS `count`
                         FROM `Challenges`
                         GROUP BY `hacker_id`
                        ) AS tmp)
       OR b.`count_count` = 1)
AND a.`count` = b.`count`
AND a.`hacker_id` = c.`hacker_id`
ORDER BY a.`count` DESC, a.`hacker_id`;