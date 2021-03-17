/**************************************
根据分数求排名, 难
首先mysql有个函数可以直接到相同效果, 那就是dense_rank
但是leetcode版本不允许使用
所以这里是其他思路
假设我要求x成绩的排名,我可以把所有比>= x的成绩拿出来
然后去重, 在使用count计算一下有多少个,那就我要的x的排名
同理,其他所有成绩的排名都可以以这种方式得到
**************************************/


select a.Score as Score,
(select count(distinct b.Score) from Scores as b where b.Score >= a.Score) as 'Rank'
from Scores as a
order by a.Score DESC