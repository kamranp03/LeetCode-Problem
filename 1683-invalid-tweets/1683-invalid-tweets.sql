# Write your MySQL query statement below
select tweet_id from tweets 
where Char_length(content)> 15;