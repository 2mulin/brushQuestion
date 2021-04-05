/********************************************************
hard
很难想到的题, 题目要求是找到每个部门前三大的工资, 包括并列的.
首先, 我想到了将数据按部门分组, 然后降序排序, 去重,找出前三大
的工资数, 在where in (....), 只要工资在..里面, 那就是的了

但是后面发现group by并不是我想的那样, 他虽然有分组的效果, 但不是
给我们用的, 他是给聚合函数使用的,比如count(),sum(), 所以我们这里使用
只会每个部门输出一行.

官方题解: where过滤 + 子查询
详细看代码,很容易理解
只要当前工资, <<同部门>>其他工资没有3个及以上 比 它还大
那么他就是该部门前三大之一
********************************************************/


select d.Name as Department, e1.Name as Employee, e1.Salary
from employee as e1, department as d
where 3 > ( # 比e1.Salary大的个数不超过3个, 说明e1就是前三大之一
    select COUNT(distinct e2.Salary)
    from employee as e2
    where e2.Salary > e1.Salary and e1.DepartmentId = e2.DepartmentId # 分部门
    )
and e1.DepartmentId = d.Id