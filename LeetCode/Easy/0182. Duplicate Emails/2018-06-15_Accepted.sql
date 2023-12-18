# Write your MySQL query statement below

SELECT Email
FROM (
    SELECT Email, COUNT(*) AS c
    FROM Person
    GROUP BY Email
) tmp
WHERE c > 1;