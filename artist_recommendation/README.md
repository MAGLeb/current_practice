# ArtistRecommendation

Чтобы запустить первые два notebooka (**prepare_data** and **prepare_authors_history**) нужно скачать данные по ссылке ниже.
Ссылка: 30Music [http://recsys.deib.polimi.it/datasets/]

Если не хотите смотреть на обработку JSON файлов, то можно скачать подготовленный для рекомендации артистов notebook (**Nearest Neighbors Algorithms** и **prepare_authors_history.csv**).

***

**prepare_data** - notebook с предобработкой JSON объектов в отдельные DataFrames. <br />
**prepare_authors_history** - notebook с созданием из отдельных DataFrames истории прослушивания исполнителей

**prepare_authors_history.csv**
- author_id (id исполнителя)
- ratio (величина показывающая на сколько процентов прослушали трек. 1 - в среднем слушают полностью трек, > 1 - несколько раз подряд в среднем, < 1 - не дослушивают до конца в среднем)
- playstart (среднее время начала трека в плейлисте у исполнителя)
- likes (количество лайков у треков исполнителя)
- duration (средняя продолжительность треков исполнителя)
- albums (количество альбомов)
- real_count_tracks (сколько раз прослушали треки с повторами)
- count_tracks (сколько всего треков)

**Nearest Neighbors Algorithms** - notebook с кластеризацией и алгоритмами рекомендаций


