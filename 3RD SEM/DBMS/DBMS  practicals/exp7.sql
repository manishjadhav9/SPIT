SELECT dept_name, AVG(budget) AS avg_budget
FROM department
GROUP BY dept_name
HAVING AVG(budget) > 80000;
