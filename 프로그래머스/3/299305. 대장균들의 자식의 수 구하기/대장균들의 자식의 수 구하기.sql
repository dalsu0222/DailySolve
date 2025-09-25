select e.ID, (
    select count(*)
    from ECOLI_DATA c
    where e.ID = c.PARENT_ID
) as CHILD_COUNT
from ECOLI_DATA e
order by ID asc;