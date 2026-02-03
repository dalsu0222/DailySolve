# 3세대의 부모 -> 2세대, 2세대 부모-> 1세대 이므로
# 2번 self join 이용하여 해결
select d3.ID
from ECOLI_DATA d3
join ECOLI_DATA d2 on d3.PARENT_ID = d2.ID
join ECOLI_DATA d1 on d2.PARENT_ID = d1.ID
where d1.PARENT_ID is null
order by d3.ID
;