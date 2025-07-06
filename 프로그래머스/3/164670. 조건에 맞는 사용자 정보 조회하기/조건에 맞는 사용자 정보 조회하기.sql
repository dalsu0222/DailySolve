select u.USER_ID, u.NICKNAME, CONCAT_WS(' ', u.CITY, u.STREET_ADDRESS1, u.STREET_ADDRESS2) as 전체주소, 
CONCAT(
    SUBSTRING(u.TLNO, 1,3), '-',
    SUBSTRING(u.TLNO, 4,4), '-',
    SUBSTRING(u.TLNO, 8,4)
) as 전화번호
from USED_GOODS_USER u
join(
    select WRITER_ID, count(*) as 개수
    from USED_GOODS_BOARD
    group by WRITER_ID
    having 개수 >= 3
) b on b.WRITER_ID = u.USER_ID
order by u.USER_ID desc;
