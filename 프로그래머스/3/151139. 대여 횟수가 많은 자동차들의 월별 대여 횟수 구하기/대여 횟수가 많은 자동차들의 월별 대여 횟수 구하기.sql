select MONTH(START_DATE) as MONTH, CAR_ID, COUNT(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where START_DATE between '2022-08-01' and '2022-10-31'
and CAR_ID in (
    # 서브 쿼리로 5회 이상인 차량만 필터링!!! 
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE between '2022-08-01' and '2022-10-31'
    group by CAR_ID
    having COUNT(*) >= 5
)
group by MONTH(START_DATE), CAR_ID
order by MONTH, CAR_ID desc;