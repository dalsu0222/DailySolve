select o.ANIMAL_ID, o.ANIMAL_TYPE, o.NAME
from ANIMAL_OUTS o
join ANIMAL_INS i on i.ANIMAL_ID = o.ANIMAL_ID
where i.SEX_UPON_INTAKE like 'Intact%'
# or 조건절 2번 풀로 기입해야함(OUTCOME like 'Neutered%' OR OUTCOME like 'Spayed%')
and (o.SEX_UPON_OUTCOME like 'Neutered%' 
or o.SEX_UPON_OUTCOME like 'Spayed%')
order by o.ANIMAL_ID
;