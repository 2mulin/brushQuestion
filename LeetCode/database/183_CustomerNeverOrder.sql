/*******************************************************
编写一个 SQL 查询，查找 从来没有买过商品的顾客

1. 子查询 + not in
先查出所有买国商品的顾客ID, 然后使用not in输出不在这里面的
其它顾客
*******************************************************/

select c.Name  as Customers
from Customers as c
where c.Id not in(
    select CustomerId from Orders
)