select date_format(t.SALES_DATE,'%Y-%m-%d') as 'SALES_DATE', t.PRODUCT_ID, t.USER_ID, t.SALES_AMOUNT
from (
    select PRODUCT_ID, USER_ID, SALES_AMOUNT, SALES_DATE
    from ONLINE_SALE
    where SALES_DATE between '2022-03-01' and '2022-03-31'
    
    union all
    
    select PRODUCT_ID, null as 'USER_ID', SALES_AMOUNT, SALES_DATE
    from OFFLINE_SALE
    where SALES_DATE between '2022-03-01' and '2022-03-31'
) t
order by SALES_DATE, PRODUCT_ID, USER_ID
;
