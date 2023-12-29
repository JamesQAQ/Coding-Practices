/*
 * Unreasonable test case: no products are sold but we should output 0 for it.
 */
SELECT
    Prices.product_id,
    IFNULL(
        ROUND(SUM(Prices.price * UnitsSold.units) / SUM(UnitsSold.units), 2), 0)
        AS average_price
  FROM Prices
  LEFT JOIN UnitsSold
  ON Prices.product_id = UnitsSold.product_id
      AND Prices.start_date <= UnitsSold.purchase_date
      AND UnitsSold.purchase_date <= Prices.end_date
  GROUP BY product_id;
