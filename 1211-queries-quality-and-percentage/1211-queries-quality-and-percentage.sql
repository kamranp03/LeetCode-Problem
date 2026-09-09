select query_name,
Round( sum(rating / position) / count(*), 2) as quality,
Round( sum(rating < 3) * 100 / count(*), 2) as poor_query_percentage
from Queries
group by query_name;