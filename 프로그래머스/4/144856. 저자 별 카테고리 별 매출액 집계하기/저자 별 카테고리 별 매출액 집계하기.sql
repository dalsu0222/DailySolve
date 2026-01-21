select b.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, 
sum(b.PRICE * s.SALES) # join된 행마다 계산 됨, 나중에 group by로 합침
as TOTAL_SALES
from BOOK b
join AUTHOR a on a.AUTHOR_ID = b.AUTHOR_ID
join BOOK_SALES s on s.BOOK_ID = b.BOOK_ID # book_sales 에서 같은 book_id의 행 개수 만큼 최종 테이블에서 같은 book_id를 가진 행이 생김.
where s.SALES_DATE >= '2022-01-01' and s.SALES_DATE <  '2022-02-01'
group by b.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY
order by b.AUTHOR_ID, b.CATEGORY desc
;