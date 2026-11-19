# Write your MySQL query statement below
-- Compare each row with the next two consecutive IDs.
SELECT DISTINCT
    l1.num AS ConsecutiveNums
FROM Logs l1

-- Join the next row.
JOIN Logs l2
    ON l1.id + 1 = l2.id

-- Join the row after that.
JOIN Logs l3
    ON l1.id + 2 = l3.id

-- All three consecutive rows must contain the same number.
WHERE
    l1.num = l2.num
    AND l2.num = l3.num;