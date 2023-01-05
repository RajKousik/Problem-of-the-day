# Write your MySQL query statement below
SELECT email from Person 
GROUP BY email
Having Count(email) > 1;