SELECT
    subquery.company_name,
    COUNT(subquery.cab_id) AS trips_amount
FROM
    trips
LEFT JOIN
    (
    SELECT --select cab_id and company_name for 2019-11-15 and 2019-11-16
        cab_id,
        company_name
    FROM
        cabs
    ) AS subquery ON subquery.cab_id = trips.cab_id
WHERE
    CAST(trips.start_ts AS date) in
    ('2017-11-01',
     '2017-11-02',
     '2017-11-03',
     '2017-11-04',
     '2017-11-05',
     '2017-11-06',
     '2017-11-07') AND
     (subquery.company_name LIKE '%Yellow%' OR subquery.company_name LIKE '%Blue%')
GROUP BY
    subquery.company_name
ORDER BY
    trips_amount DESC;