select b.CATEGORY, sum(SALES) as TOTAL_SALES
from (
    select BOOK_ID, sum(SALES) as SALES
    from BOOK_SALES
    where SALES_DATE between '2022-01-01' and '2022-01-31'
    group by BOOK_ID
) s
join BOOK b on b.BOOK_ID = s.BOOK_ID
group by b.CATEGORY
order by b.CATEGORY
;