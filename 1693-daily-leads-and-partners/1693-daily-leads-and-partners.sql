# Write your MySQL query statement below

select date_id,make_name, count(distinct(lead_id)) as unique_leads,count(distinct(partner_id)) as unique_partners
from dailySales
group by date_id,make_name