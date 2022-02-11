SELECT
    ts,
    case
        when description like '%rain%' or description like '%storm%' then 'Bad'
        else 'Good'
    end as weather_conditions
FROM
    weather_records