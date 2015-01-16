# Write your MySQL query statement below
select Salary as SecondHighestSalary
from (  select distinct Salary
        from Employee
        order by Salary DESC
        limit 1, 1  )
as Candidate
union
select NULL limit 1;
