# Write your MySQL query statement below
select user_id, MAX(time_stamp) as last_stamp
from Logins
Where time_stamp like '2020%'
GROUP BY user_id;