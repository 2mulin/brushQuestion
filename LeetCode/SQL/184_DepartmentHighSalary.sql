/********************************************
* 这里注意where in的用发
*  (e.DepartmentId, e.Salary) in
* in里面有两个字段
********************************************/

select
       d.Name as 'Department',
       e.Name as 'Employee',
       e.Salary as 'Salary'
from Employee as e
    join Department as d on e.DepartmentId=d.Id 
where (e.DepartmentId, e.Salary) in
    (
        select DepartmentId, max(Salary)
        from Employee
        group by DepartmentId
    )