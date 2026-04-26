# Write your MySQL query statement below
SELECT *
    FROM Cinema
    WHERE description != 'boring'
    AND mod(ID, 2) = 1
    ORDER BY rating DESC
;