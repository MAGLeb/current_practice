SELECT
    start_ts,
    CASE
        WHEN description LIKE '%rain%' OR description LIKE '%storm%' THEN 'Bad'
        ELSE 'Good'
    END AS weather_conditions,
    duration_seconds
FROM
    trips
INNER JOIN weather_records ON weather_records.ts = trips.start_ts
WHERE
    trips.pickup_location_id = 50 AND
    trips.dropoff_location_id = 63 AND
    EXTRACT(isodow FROM trips.start_ts) = 6
ORDER BY
    trips.start_ts;