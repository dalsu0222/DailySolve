select new_e.ID, case 
    when new_e.rnk <= 0.25 then 'CRITICAL'
    when new_e.rnk <= 0.5 then 'HIGH'
    when new_e.rnk <= 0.75 then 'MEDIUM'
    else 'LOW'
end as COLONY_NAME
from ( # PERCENT_RANK(): 상대 순위 함수로, 현재 행 값에 대해 0~1 사이의 상대값을 리턴
    select ID,
    PERCENT_RANK() over (order by SIZE_OF_COLONY desc) as rnk
    from ECOLI_DATA
) as new_e
order by new_e.ID
;
