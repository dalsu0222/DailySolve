select a.APNT_NO, p.PT_NAME, p.PT_NO, a.MCDP_CD, d.DR_NAME, a.APNT_YMD
from APPOINTMENT a
join PATIENT p on p.PT_NO = a.PT_NO
join DOCTOR d on d.DR_ID = a.MDDR_ID
where year(a.APNT_YMD) = 2022 
and month(a.APNT_YMD) = 4 
and day(a.APNT_YMD) = 13 
and a.APNT_CNCL_YN = 'N'
order by a.APNT_YMD
;