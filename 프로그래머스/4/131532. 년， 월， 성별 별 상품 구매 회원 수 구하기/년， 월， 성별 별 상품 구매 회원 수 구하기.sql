select year(s.SALES_DATE) as 'YEAR', month(s.SALES_DATE) as 'MONTH',
i.GENDER, count(distinct s.USER_ID) as 'USERS'
# 그냥 count(*) -> 구매건수 전부 포함, 같은 달에 같은 회원이 여러번 사면 전부 카운팅 됨
# count(s.USER_ID) -> USER_ID가 null이 아닌 행의 수, 의미 없음!
from ONLINE_SALE s
join USER_INFO i on i.USER_ID = s.USER_ID
where i.GENDER is not null
group by YEAR, MONTH, i.GENDER
order by YEAR, MONTH, i.GENDER
;