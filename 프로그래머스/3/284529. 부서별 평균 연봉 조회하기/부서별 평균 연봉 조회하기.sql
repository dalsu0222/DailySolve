select d.DEPT_ID, d.DEPT_NAME_EN, ae.AVG_SAL
from HR_DEPARTMENT d
join (
    select DEPT_ID, ROUND(AVG(SAL), 0) as AVG_SAL
    from HR_EMPLOYEES
    group by DEPT_ID
) ae on ae.DEPT_ID = d.DEPT_ID
order by ae.AVG_SAL desc;