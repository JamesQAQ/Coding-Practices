SELECT tmp1.cnt - tmp2.cnt
FROM
    (SELECT COUNT(*) AS cnt FROM `STATION`) AS tmp1,
    (SELECT COUNT(DISTINCT `CITY`) AS cnt FROM `STATION`) AS tmp2;