SELECT REPEAT('* ', @i:=@i+1)
FROM information_schema.tables, (SELECT @i:=0) AS i
LIMIT 20;