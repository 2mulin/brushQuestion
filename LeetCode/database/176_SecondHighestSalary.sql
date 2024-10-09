/*******************************************************
编写一个 SQL 查询，获取 Employee 表中第二高的薪水（Salary）

1. 
将不同的薪资按降序排序，然后使用 LIMIT 子句获得第二高的薪资。
注意null的情况
2. 
去掉最大值而后排序
*******************************************************/

-- 1. 降序，limits输出第二个
SELECT DISTINCT
    Salary AS SecondHighestSalary
FROM
    Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1
-- 避免出现只有一行的情况，需要输出null
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;

-- 2 去掉最大值
SELECT max(Salary) AS SecondHighestSalary 
FROM Employee
where Salary < (select max(Salary) from Employee);