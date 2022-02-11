## Project Description
Analytics work for taxi company, a new ride-sharing company that's launching in Chicago. Task is to find patterns in the available information. I want to understand passenger preferences and the impact of external factors on rides.
I'll study a database, analyze data from competitors, and test a hypothesis about the impact of weather on ride frequency.


<h3 class="text_center">Description of the data</h3>

A database with info on taxi rides in Chicago:<br>

<code class="code-inline_theme_light">neighborhoods</code> table: data on city neighborhoods<br>
    - name: name of the neighborhood<br>
    - neighborhood_id: neighborhood code<br>
<code class="code-inline_theme_light">cabs</code> table: data on taxis<br>
    - cab_id: vehicle code<br>
    - vehicle_id: the vehicle's technical ID<br>
    - company_name: the company that owns the vehicle<br>
<code class="code-inline_theme_light">trips</code> table: data on rides<br>
    - trip_id: ride code<br>
    - cab_id: code of the vehicle operating the ride<br>
    - start_ts: date and time of the beginning of the ride (time rounded to the hour)<br>
    - end_ts: date and time of the end of the ride (time rounded to the hour)<br>
    - duration_seconds: ride duration in seconds<br>
    - distance_miles: ride distance in miles<br>
    - pickup_location_id: pickup neighborhood code<br>
    - dropoff_location_id: dropoff neighborhood code<br>
<code class="code-inline_theme_light">weather_records</code> table: data on weather<br>
    - record_id: weather record code<br>
    - ts: record date and time (time rounded to the hour)<br>
    - temperature: temperature when the record was taken<br>
    - description: brief description of weather conditions, e.g. "light rain" or "scattered clouds"<br>

![SQL tables](https://i.paste.pics/9NHWO.png)
