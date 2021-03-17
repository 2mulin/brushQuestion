/*******************************************************
编写一个存储过程，获取 Employee 表中第N高的薪水（Salary）

将不同的薪资按降序排序，然后使用 LIMIT 子句获得第二高的薪资。
注意null的情况, 使用IFNULL函数判断select结果为NULL
*******************************************************/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE idx INT;  -- 声明参数
  set idx=N-1;      -- 设置参数的值
  -- 返回值
  RETURN (
      # Write your MySQL query statement below.
      select IFNULL(
      (select distinct Salary
      from Employee
      order by Salary desc
      limit 1 offset idx)
      , NULL)
  );
END