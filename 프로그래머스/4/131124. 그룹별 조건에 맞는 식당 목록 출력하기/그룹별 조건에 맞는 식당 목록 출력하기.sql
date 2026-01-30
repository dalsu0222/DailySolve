select p.MEMBER_NAME, r.REVIEW_TEXT, date_format(r.REVIEW_DATE,'%Y-%m-%d') as 'REVIEW_DATE'
from REST_REVIEW r
join MEMBER_PROFILE p on p.MEMBER_ID = r.MEMBER_ID
where r.MEMBER_ID = ( # 결과물이 스칼라 서브쿼리일때는 in 대신 = 사용
  select MEMBER_ID
  from REST_REVIEW
  group by MEMBER_ID
  order by count(*) desc
  limit 1 # 내림차순해서 가장 위에 것 = max 효과
)
order by r.REVIEW_DATE, r.REVIEW_TEXT;
