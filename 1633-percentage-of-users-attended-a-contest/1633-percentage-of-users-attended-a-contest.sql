# Write your MySQL query statement below

select distinct(contest_id), ROUND((count(distinct(register.user_id))/count(distinct(users.user_id)))*100,2) as percentage
from register,users
group by contest_id
order by percentage desc,contest_id 