with recursive h as( # with recursive: 재귀, 반복문처럼 사용 가능
    select 0 as hr # 처음엔 hr=0 1개로 시작
    union
    select hr + 1 from h where hr < 23 # 조건 설정
)
select h.hr as 'HOUR', ifnull(o.COUNT, 0) as 'COUNT'
from h
left join (
    select hour(DATETIME) as HOUR, count(*) as 'COUNT'
    from ANIMAL_OUTS
    group by HOUR
) o on o.HOUR = h.hr
;