select t.ITEM_ID, i.ITEM_NAME, i.RARITY
from ITEM_tree t
join ITEM_INFO i on i.ITEM_ID = t.ITEM_ID
where t.ITEM_ID not in (
    select distinct PARENT_ITEM_ID
    from ITEM_TREE
    where PARENT_ITEM_ID is not null
)
order by t.ITEM_ID desc
;