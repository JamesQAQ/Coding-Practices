SELECT a.`Name`
FROM `Students` a, `Friends` b, `Packages` c, `Packages` d
WHERE a.`ID` = b.`ID` AND a.`ID` = c.`ID` AND b.`Friend_ID` = d.`ID` AND c.`Salary` < d.`Salary`
ORDER BY d.`Salary`;