select CART_ID
from CART_PRODUCTS
where NAME in ('Milk','Yogurt')
group by CART_ID
having count(distinct NAME) = 2 # 행의 값에 들어있는 종류 개수 확인 위해 'distinct 컬럼이름' 사용
order by CART_ID
;