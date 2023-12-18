# Write your MySQL query statement below
SELECT `class`
FROM (
    SELECT `class`, COUNT(*) as `count`
    FROM `Courses`
    GROUP BY `class`) as `t`
WHERE `count` >= 5;