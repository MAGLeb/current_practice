SELECT
	musicians.name,
    labels.name,
    albums.name,
    albums.rating
FROM
    albums
    INNER join musicians ON albums.musician_id = musicians.id
    INNER JOIN labels ON albums.label_id = labels.id
WHERE
	(labels.name == 'Скрипичный ключ' OR labels.name == 'Граммофон')
	AND (albums.rating < 10)
	AND (albums.rating > 4)
ORDER BY
    musicians.name