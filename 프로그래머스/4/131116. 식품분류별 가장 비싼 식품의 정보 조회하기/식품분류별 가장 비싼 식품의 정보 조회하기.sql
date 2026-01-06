# 각 행이 그 카테고리의 최대가격인가? 를 검사
select p.CATEGORY, p.PRICE as 'MAX_PRICE', p.PRODUCT_NAME
from FOOD_PRODUCT p
where p.CATEGORY in ('과자','국','김치','식용유')
and p.PRICE = (
    select MAX(PRICE)
    from FOOD_PRODUCT
    where CATEGORY = p.CATEGORY
)
order by MAX_PRICE desc
;
