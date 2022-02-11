SELECT
    CASE
        WHEN cabs.company_name NOT IN ('Flash Cab', 'Taxi Affiliation Services') THEN 'Other'
        ELSE cabs.company_name
    END AS company,
    COUNT(trips.trip_id) AS trips_amount  
FROM
    trips
LEFT JOIN cabs ON cabs.cab_id = trips.cab_id
WHERE
    CAST(trips.start_ts AS date) >= '2017-11-01' AND
    CAST(trips.start_ts AS date) < '2017-11-08'
GROUP BY
    company
ORDER BY
    trips_amount DESC;