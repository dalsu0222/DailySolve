select f.FLAVOR
from FIRST_HALF f
join (
    select FLAVOR, sum(TOTAL_ORDER) as 'TOTAL_ORDER'
    from JULY
    group by FLAVOR
) j on f.FLAVOR = j.FLAVOR
order by (f.TOTAL_ORDER + j.TOTAL_ORDER) desc
limit 3
;
