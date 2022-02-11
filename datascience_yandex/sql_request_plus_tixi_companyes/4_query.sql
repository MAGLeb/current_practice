SELECT
    SUBQ.dropoff_location_name AS dropoff_location_name,
    AVG(SUBQ.average_trips) AS average_trips
FROM
    (SELECT
        EXTRACT(day from trips.end_ts) AS day,
        COUNT(trips.trip_id) AS average_trips,
        neighborhoods.name AS dropoff_location_name
    FROM
        trips
    INNER JOIN neighborhoods ON neighborhoods.neighborhood_id = trips.dropoff_location_id
    GROUP BY
         day,
         dropoff_location_name) AS SUBQ
GROUP BY
    dropoff_location_name
ORDER BY
    average_trips DESC;