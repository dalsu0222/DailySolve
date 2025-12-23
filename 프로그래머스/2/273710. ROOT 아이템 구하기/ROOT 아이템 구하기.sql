select i.ITEM_ID, i.ITEM_NAME
from ITEM_INFO i
join ITEM_TREE t on t.ITEM_ID = i.ITEM_ID
where t.PARENT_ITEM_ID is null # having 절은 group by 결과에서만 쓴다
;