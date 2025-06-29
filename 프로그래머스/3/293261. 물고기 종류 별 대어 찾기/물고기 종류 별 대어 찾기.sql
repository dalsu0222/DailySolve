SELECT i.id, ni.FISH_NAME, i.LENGTH
FROM FISH_INFO i
join (
    select FISH_TYPE, max(LENGTH) as LENGTH
    from FISH_INFO
    group by FISH_TYPE
) mi
on i.FISH_TYPE = mi.FISH_TYPE
and i.LENGTH = mi.LENGTH

join FISH_NAME_INFO ni
on i.FISH_TYPE = ni.FISH_TYPE
;
