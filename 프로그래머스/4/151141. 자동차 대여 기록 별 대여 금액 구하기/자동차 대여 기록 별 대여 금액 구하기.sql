# diff 구해서
# 할인율 찾고
# 일일렌탈료 x 총 대여일에 할인률 적용
# 총 금액은 정수로만 출력

select h.HISTORY_ID,
round(
    c.DAILY_FEE
    * (datediff(h.END_DATE, h.START_DATE) + 1)
    * (100 - ifnull((
        select p.DISCOUNT_RATE
        from CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
        where p.CAR_TYPE = c.CAR_TYPE
          and p.DURATION_TYPE = (case
            when (datediff(h.END_DATE, h.START_DATE) + 1) >= 90 THEN '90일 이상'
            when (datediff(h.END_DATE, h.START_DATE) + 1) >= 30 THEN '30일 이상'
            when (datediff(h.END_DATE, h.START_DATE) + 1) >= 7  THEN '7일 이상'
            ELSE NULL
          end)
    ), 0)) / 100
) as FEE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
join CAR_RENTAL_COMPANY_CAR c on c.CAR_ID = h.CAR_ID
where c.CAR_TYPE = '트럭'
order by FEE desc, h.HISTORY_ID desc
;