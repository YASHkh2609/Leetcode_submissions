# Write your MySQL query statement below
SELECT Department.name as Department, Employee.name as Employee, salary as Salary
FROM Employee
LEFT JOIN Department
ON Employee.departmentId=Department.id
WHERE (Salary, departmentId) in (SELECT max(salary), departmentId
                    FROM Employee
                    GROUP BY departmentId);
