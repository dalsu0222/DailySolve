select p.CATEGORY, np.MAX_PRICE, p.PRODUCT_NAME
from FOOD_PRODUCT p
join (
    select CATEGORY, MAX(PRICE) as MAX_PRICE
    from FOOD_PRODUCT
    where CATEGORY in ('과자','국','김치','식용유')
    group by CATEGORY
) np on np.CATEGORY = p.CATEGORY and np.MAX_PRICE = p.PRICE
order by np.MAX_PRICE desc
;