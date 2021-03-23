/*********************************************
* 删除重复的Email, 只保留Id最小的那一行数据
* 自联结, 删除Id大的那一个
*********************************************/


delete P1.*
from Person as p1, Person as p2
where p1.Email = p2.Email and p1.Id > p2.Id;