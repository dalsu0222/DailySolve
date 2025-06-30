select distinct rh.CAR_ID 
from CAR_RENTAL_COMPANY_RENTAL_HISTORY rh
join CAR_RENTAL_COMPANY_CAR c
on rh.CAR_ID = c.CAR_ID
where c.CAR_TYPE = '세단'
and rh.START_DATE between '2022-10-01' and '2022-10-31'
order by rh.CAR_ID desc;