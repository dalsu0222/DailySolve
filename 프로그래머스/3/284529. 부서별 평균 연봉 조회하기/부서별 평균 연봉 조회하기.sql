select d.DEPT_ID, d.DEPT_NAME_EN, round(avg(h.SAL),0) as AVG_SAL
from HR_EMPLOYEES h
join HR_DEPARTMENT d on h.DEPT_ID = d.DEPT_ID
group by h.DEPT_ID
order by AVG_SAL desc
;