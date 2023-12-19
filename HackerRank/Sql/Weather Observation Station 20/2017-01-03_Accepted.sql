SELECT ROUND(`LAT_N`, 4) FROM
(
    SELECT a.`ID`, a.`LAT_N`, COUNT(*) as `RANK`
    FROM `STATION` a, `STATION` b
    WHERE a.`LAT_N` > b.`LAT_N`
    OR (a.`LAT_N` = b.`LAT_N` AND a.`ID` > b.`ID`)
    GROUP BY a.`ID`
) tmp
WHERE `RANK` = FLOOR((SELECT COUNT(*) FROM `STATION`) / 2);
