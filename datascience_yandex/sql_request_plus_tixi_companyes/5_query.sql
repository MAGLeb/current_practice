SELECT
    neighborhood_id,
    name
FROM
    neighborhoods
GROUP BY
    neighborhood_id,
    name
HAVING
    name LIKE '%Hare' OR name LIKE 'Loop'