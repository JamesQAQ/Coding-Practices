SELECT
    contest_id,
    ROUND(COUNT(*) * 100 / total, 2) AS percentage
  FROM Register
  LEFT JOIN (SELECT COUNT(*) AS total FROM Users) AS tmp
    ON true
  GROUP BY contest_id
  ORDER BY percentage DESC, contest_id ASC;
