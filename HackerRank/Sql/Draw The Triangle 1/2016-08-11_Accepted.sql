SELECT REPEAT('* ', @i:=@i-1)
FROM information_schema.tables, (SELECT @i:=21) AS i
LIMIT 20;
