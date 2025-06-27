# case when 조건문 : 구간별로 라벨링하기 
select ID , case
    when SIZE_OF_COLONY <= 100 then 'LOW'
    when SIZE_OF_COLONY <= 1000 then 'MEDIUM'
    else 'HIGH'
    end as SIZE
from ECOLI_DATA
order by ID asc;