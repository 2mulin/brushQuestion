/*******************************************************
* @author reddragon
* @date 2020/10/24
* @brief 查找重复的电子邮箱
* 编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。
1. 子查询
可以根据Email分组，找出同一个Email出现的次数
在输出Email出现次数大于2的.
2. 分组查询
根据Email分组，利用having子句过滤分组
*******************************************************/
select Email from
    (select Email,count(Email) as num
    from Person
    group by Email) as ta
where ta.num > 1;

select Email from Person
group by Email
having count(Email) > 1;