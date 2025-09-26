select p.CATEGORY, p.PRICE as MAX_PRICE, p.PRODUCT_NAME
from FOOD_PRODUCT p
join (
    select CATEGORY, max(PRICE) as PRICE
    from FOOD_PRODUCT
    where CATEGORY in ('과자','국','김치','식용유')
    group by CATEGORY
) n on n.CATEGORY = p.CATEGORY
and p.PRICE = n.PRICE
order by MAX_PRICE desc
;