SELECT CATEGORY, SUM(sales) as 'TOTAL_SALES'
from BOOK b
join BOOK_SALES s on b.BOOK_ID = s.BOOK_ID
where s.SALES_DATE between '2022-01-01' and '2022-01-31'
group by CATEGORY
order by CATEGORY asc;