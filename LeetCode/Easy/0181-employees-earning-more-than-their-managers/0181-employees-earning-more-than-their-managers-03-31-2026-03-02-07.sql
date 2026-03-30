# Write your MySQL query statement below
SELECT A.name as Employee
    FROM Employee A
    INNER JOIN Employee B
    WHERE A.managerId = B.id
    AND A.salary > B.salary;