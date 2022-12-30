# Write your MySQL query statement below
SELECT
id, 
IF(ISNULL(p_id), 'Root',
IF(id IN (SELECT p_id FROM Tree), 'Inner', 'Leaf')) AS type
FROM Tree
ORDER BY id;

