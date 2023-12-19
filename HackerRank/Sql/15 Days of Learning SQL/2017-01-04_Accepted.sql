SELECT a.`submission_date`, b.`count`, a.`hacker_id`, c.`name`
FROM (SELECT a.`submission_date`, MIN(b.`hacker_id`) AS `hacker_id`
        FROM (SELECT `submission_date`, MAX(`count`) AS `count`
              FROM (SELECT `submission_date`, COUNT(*) AS `count`
                    FROM `Submissions`
                    GROUP BY `submission_date`, `hacker_id`) tmp
              GROUP BY `submission_date`) a,
             (SELECT `submission_date`, `hacker_id`, COUNT(*) AS `count`
              FROM `Submissions`
              GROUP BY `submission_date`, `hacker_id`) b
        WHERE a.`submission_date` = b.`submission_date`
          AND a.`count` = b.`count`
        GROUP BY a.`submission_date`) a,
      (SELECT `end_date` AS `submission_date`, COUNT(*) AS `count`
FROM (SELECT `end_date`, COUNT(*) AS `count`, `cc`
        FROM (SELECT a.`submission_date`, b.`submission_date` AS `end_date`, a.`hacker_id`, `cc`
                FROM `Submissions` a,
                     (SELECT @i:=@i+1 AS `cc`, `submission_date`
                      FROM (SELECT DISTINCT(`submission_date`)
                            FROM `Submissions`) tmp, (SELECT @i:=0) AS i
                      ORDER BY `submission_date`) b
                WHERE a.`submission_date` <= b.`submission_date`
                GROUP BY a.`submission_date`, b.`submission_date`, a.`hacker_id`) tmp
        GROUP BY `end_date`, `hacker_id`) tmp
WHERE `cc` = `count`
GROUP BY `end_date`) b,
     `Hackers` c
WHERE a.`submission_date` = b.`submission_date`
  AND a.`hacker_id` = c.`hacker_id`
ORDER BY a.`submission_date`;