select b.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, sum(b.PRICE * s.SALES) as TOTAL_SALES
from BOOK b
join BOOK_SALES s on b.BOOK_ID = s.BOOK_ID
left join AUTHOR a on a.AUTHOR_ID = b.AUTHOR_ID
where s.SALES_DATE between '2022-01-01' and '2022-01-31'
group by a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY
order by b.AUTHOR_ID asc, b.CATEGORY desc
;