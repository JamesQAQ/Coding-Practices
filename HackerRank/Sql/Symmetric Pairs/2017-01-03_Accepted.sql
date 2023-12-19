SELECT a.`X`, a.`Y`
FROM (SELECT `id`, `X`, `Y`
      FROM (SELECT @i:=@i+1 AS `id`, `X`, `Y`
            FROM `Functions`, (SELECT @i:=0) AS i) tmp
      WHERE `X` <= `Y`) a,
     (SELECT @j:=@j+1 AS `id`, `X`, `Y`
      FROM `Functions`, (SELECT @j:=0) AS j) b
WHERE a.`X` = b.`Y` AND a.`Y` = b.`X` AND a.`id` != b.`id`
GROUP BY a.`X`, a.`Y`
ORDER BY a.`X`;