SELECT Product.product_id, product_name
  FROM Sales
  INNER JOIN Product
  ON Sales.product_id = Product.product_id
  GROUP BY Product.product_id
  HAVING '2019-01-01' <= MIN(sale_date) AND MAX(sale_date) <= '2019-03-31';
