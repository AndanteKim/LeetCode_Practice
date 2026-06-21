# Write your MySQL query statement below
SELECT email
    FROM (
        SELECT email, count(email) as num
        FROM Person
        GROUP BY email
    ) as Statistic
    WHERE num > 1
    ;