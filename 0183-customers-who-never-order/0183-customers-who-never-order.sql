# Write your MySQL query statement below
select Customers.name as Customers from Customers
where Customers.id NOT IN
(select Orders.customerId from Orders);
