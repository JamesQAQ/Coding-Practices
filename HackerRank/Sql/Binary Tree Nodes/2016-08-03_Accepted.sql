SELECT DISTINCT `no`,
    CASE
        WHEN EXISTS(SELECT * FROM `BST` WHERE `N`=`no` AND `P` IS NOT NULL)
         AND EXISTS(SELECT * FROM `BST` WHERE `P`=`no` AND `N` IS NOT NULL) THEN 'Inner'
        WHEN EXISTS(SELECT * FROM `BST` WHERE `N`=`no` AND `P` IS NOT NULL) THEN 'Leaf'
        ELSE 'Root'
    END
FROM
   (SELECT `P` as `no` FROM `BST`
    UNION
    SELECT `N` as `no` FROM `BST`) AS union_set
WHERE `no` IS NOT NULL
ORDER BY `no`;