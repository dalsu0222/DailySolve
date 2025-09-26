select i.ITEM_ID, i.ITEM_NAME, i.RARITY
from ITEM_TREE t
join ITEM_INFO i on t.ITEM_ID = i.ITEM_ID
where t.ITEM_ID not in (
    select DISTINCT PARENT_ITEM_ID
    from ITEM_TREE 
    where PARENT_ITEM_ID is NOT NULL
)
order by t.ITEM_ID desc
;