import sqlite3

# 1. Create a connection to the database (or create it if it doesn't exist)
conn = sqlite3.connect('example.db')

# 2. Create a cursor object
cursor = conn.cursor()

# 3. Create a table (if it doesn't exist)
cursor.execute('''
CREATE TABLE IF NOT EXISTS employees (
    employee_id INTEGER PRIMARY KEY,
    first_name TEXT,
    last_name TEXT,
    salary REAL,
    department TEXT
)
''')

# 4. Insert data into the table
cursor.execute('''
INSERT INTO employees (first_name, last_name, salary, department)
VALUES ('Alice', 'Smith', 70000,'Sales')
''')
cursor.execute('''
INSERT INTO employees (first_name, last_name, salary, department)
VALUES ('Bob', 'Brown', 80000,'Sales')
''')
cursor.execute('''
UPDATE employees
SET salary = CASE
    WHEN employee_id = 1 THEN 60000
    WHEN employee_id = 2 THEN 70000
    WHEN employee_id = 3 THEN 80000
    ELSE salary
END,
first_name = CASE
    WHEN employee_id = 1 THEN 'John'
    WHEN employee_id = 2 THEN 'Jane'
    WHEN employee_id = 3 THEN 'Alice'
    ELSE first_name
END
WHERE employee_id IN (1, 2, 3);
''')
conn.commit()

# 6. Query the data
cursor.execute('SELECT * FROM employees')

# 7. Fetch and display the results
rows = cursor.fetchall()
for row in rows:
    print(row)

# 8. Close the connection
conn.close()