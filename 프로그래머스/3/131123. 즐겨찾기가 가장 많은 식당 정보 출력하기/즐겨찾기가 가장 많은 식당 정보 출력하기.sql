# 가장 많은 좋아요 수가 유일한 수인걸까? 종류가 같은데 좋아요 수가 같으면?

select r.FOOD_TYPE, r.REST_ID, r.REST_NAME, r.FAVORITES
from REST_INFO r
join(
    select FOOD_TYPE, MAX(FAVORITES) as FAVORITES 
    from REST_INFO
    group by FOOD_TYPE
) m on m.FAVORITES = r.FAVORITES and m.FOOD_TYPE = r.FOOD_TYPE
order by FOOD_TYPE desc;