select i.ANIMAL_ID,  i.NAME 
from ANIMAL_INS i
join ANIMAL_OUTS o on o.ANIMAL_ID = i.ANIMAL_ID
order by DATEDIFF(O.DATETIME, I.DATETIME) desc
limit 2;