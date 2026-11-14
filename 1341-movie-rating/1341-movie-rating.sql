# Write your MySQL query statement below
-- First query: Find the user who rated the most movies.
(
    SELECT
        u.name AS results
    FROM Users u
    JOIN MovieRating mr
        ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
    ORDER BY
        COUNT(mr.movie_id) DESC,  -- Highest number of movie ratings first
        u.name ASC                -- Lexicographically smaller name wins ties
    LIMIT 1
)

UNION ALL

-- Second query: Find the highest-rated movie in February 2020.
(
    SELECT
        m.title AS results
    FROM Movies m
    JOIN MovieRating mr
        ON m.movie_id = mr.movie_id
    WHERE
        mr.created_at >= '2020-02-01'
        AND mr.created_at < '2020-03-01' -- Only February 2020 ratings
    GROUP BY m.movie_id, m.title
    ORDER BY
        AVG(mr.rating) DESC,  -- Highest average rating first
        m.title ASC           -- Lexicographically smaller title wins ties
    LIMIT 1
);