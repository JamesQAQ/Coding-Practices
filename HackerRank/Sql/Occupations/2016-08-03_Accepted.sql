SELECT Name1, Name2, Name3, Name4
FROM
    (
        SELECT doctors.`id`, doctors.`Name` AS Name1, professors.`Name` AS Name2
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Doctor'
             ORDER BY `Name`) AS doctors
        LEFT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Professor'
             ORDER BY `Name`) AS professors
        ON doctors.id=professors.id

        UNION

        SELECT professors.`id`, doctors.`Name` AS Name1, professors.`Name` AS Name2
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Doctor'
             ORDER BY `Name`) AS doctors
        RIGHT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Professor'
             ORDER BY `Name`) AS professors
        ON doctors.id=professors.id
    ) AS dp

LEFT JOIN

    (
        SELECT singers.`id`, singers.`Name` AS Name3, actors.`Name` AS Name4
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Singer'
             ORDER BY `Name`) AS singers
        LEFT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Actor'
             ORDER BY `Name`) AS actors
        ON singers.id=actors.id

        UNION

        SELECT singers.`id`, singers.`Name` AS Name3, actors.`Name` AS Name4
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Singer'
             ORDER BY `Name`) AS singers
        RIGHT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Actor'
             ORDER BY `Name`) AS actors
        ON singers.id=actors.id
    ) AS sa
ON dp.id=sa.id

UNION

SELECT Name1, Name2, Name3, Name4
FROM
    (
        SELECT doctors.`id`, doctors.`Name` AS Name1, professors.`Name` AS Name2
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Doctor'
             ORDER BY `Name`) AS doctors
        LEFT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Professor'
             ORDER BY `Name`) AS professors
        ON doctors.id=professors.id

        UNION

        SELECT professors.`id`, doctors.`Name` AS Name1, professors.`Name` AS Name2
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Doctor'
             ORDER BY `Name`) AS doctors
        RIGHT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Professor'
             ORDER BY `Name`) AS professors
        ON doctors.id=professors.id
    ) AS dp

RIGHT JOIN

    (
        SELECT singers.`id`, singers.`Name` AS Name3, actors.`Name` AS Name4
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Singer'
             ORDER BY `Name`) AS singers
        LEFT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Actor'
             ORDER BY `Name`) AS actors
        ON singers.id=actors.id

        UNION

        SELECT singers.`id`, singers.`Name` AS Name3, actors.`Name` AS Name4
        FROM (SELECT @i:=@i+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @i:=0) AS i
             WHERE `Occupation`='Singer'
             ORDER BY `Name`) AS singers
        RIGHT JOIN
             (SELECT @j:=@j+1 AS id, `Name`
             FROM `OCCUPATIONS`, (SELECT @j:=0) AS j
             WHERE `Occupation`='Actor'
             ORDER BY `Name`) AS actors
        ON singers.id=actors.id
    ) AS sa
ON dp.id=sa.id;