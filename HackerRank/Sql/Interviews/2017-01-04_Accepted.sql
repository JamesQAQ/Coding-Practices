SELECT a.`contest_id`, a.`hacker_id`, a.`name`, a.`r1`, a.`r2`, b.`r3`, b.`r4`
FROM (SELECT a.`contest_id`, a.`hacker_id`, a.`name`, SUM(d.`total_submissions`) AS `r1`, SUM(d.`total_accepted_submissions`) AS `r2`
      FROM `Contests` a, `Colleges` b, `Challenges` c, `Submission_Stats` d
      WHERE a.`contest_id` = b.`contest_id`
      AND b.`college_id` = c.`college_id`
      AND c.`challenge_id` = d.`challenge_id`
      GROUP BY a.`contest_id`) a,
     (SELECT a.`contest_id`, SUM(d.`total_views`) AS `r3`, SUM(d.`total_unique_views`) AS `r4`
      FROM `Contests` a, `Colleges` b, `Challenges` c, `View_Stats` d
      WHERE a.`contest_id` = b.`contest_id`
      AND b.`college_id` = c.`college_id`
      AND c.`challenge_id` = d.`challenge_id`
      GROUP BY a.`contest_id`) b
WHERE a.`contest_id` = b.`contest_id`
ORDER BY a.`contest_id`;