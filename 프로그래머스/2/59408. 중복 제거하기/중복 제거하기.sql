SELECT COUNT(DISTINCT UPPER(NAME)) AS count
FROM ANIMAL_INS 
WHERE NAME IS NOT NULL;
