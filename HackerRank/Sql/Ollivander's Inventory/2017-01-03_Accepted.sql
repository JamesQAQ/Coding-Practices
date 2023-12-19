SELECT a.`id`, b.`age`, a.`coins_needed`, a.`power`
FROM `Wands` a, `Wands_Property` b,
(SELECT `code`, `power`, MIN(`coins_needed`) as `min_coins_needed`
FROM `Wands`
GROUP BY `code`, `power`) c
WHERE a.`code` = b.`code` AND b.`is_evil` = 0
AND a.`coins_needed` = c.`min_coins_needed`
AND a.`code` = c.`code` AND a.`power` = c.`power`
ORDER BY a.`power` DESC, b.`age` DESC, a.`coins_needed`;
