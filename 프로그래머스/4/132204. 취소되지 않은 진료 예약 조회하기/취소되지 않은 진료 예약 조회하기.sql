select a.APNT_NO, p.PT_NAME, a.PT_NO, a.MCDP_CD, d.DR_NAME, a.APNT_YMD
from APPOINTMENT a
join PATIENT p on p.PT_NO = a.PT_NO
join DOCTOR d on d.DR_ID = a.MDDR_ID
where substring(a.APNT_YMD,1,10) = '2022-04-13'
and a.MCDP_CD = 'CS'
and a.APNT_CNCL_YN = 'N'
order by a.APNT_YMD
;