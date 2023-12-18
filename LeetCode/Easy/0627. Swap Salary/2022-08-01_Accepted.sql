# Write your MySQL query statement below
UPDATE `Salary` SET `sex` = CHAR(ASCII('m') + ASCII('f') - ASCII(`sex`));