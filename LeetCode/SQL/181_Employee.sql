/*********************************
查出比经理工资高的员工, 很好查
一个自连接就解决了, 只要id是经理的ID
并且工资比员工低, 那就是对的
*********************************/


Select a.Name as Employee
from Employee as a, Employee as b
where b.Id = a.ManagerId and a.Salary > b.Salary;