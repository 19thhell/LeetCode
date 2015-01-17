# Write your MySQL query statement below
select E.Name as Employee
from Employee as E inner join Employee as M
on E.ManagerId = M.Id
where E.Salary > M.salary;
