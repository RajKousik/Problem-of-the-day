# Write your MySQL query statement below
SELECT employee_id, 
CASE
    WHEN employee_id % 2 AND name NOT LIKE 'M%' 
        THEN salary
        ELSE 0
END
as bonus
from Employees
order by employee_id;
