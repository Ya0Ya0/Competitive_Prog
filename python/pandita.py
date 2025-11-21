import csv
import pandas as pd
import matplotlib.pyplot as plt

# Load CSV data
# Create a dictionary of data
data = {
    'Column1': ['John', 'Alice', 'Bob'],
    'Column2': [23, 25, 22],    
}

# Convert the dictionary into a DataFrame
df = pd.DataFrame(data)

# Replace 'output.csv' with your desired file path
df.to_csv('output.csv', index=False)
        



# Load the CSV data into a pandas DataFrame
df = pd.read_csv('output.csv')  # Replace 'path_to_your_file.csv' with the actual path to your CSV file

# Assume the first column is 'X' and the second column is 'Y'
x = df.iloc[0]  # Selects the first column
y = df.iloc[1]  # Selects the second column
x = df['Column1']
y = df['Column2']
# Plotting
plt.figure(figsize=(10, 6))  # Optional: Adjusts the figure size
plt.plot(x, y)  # You can change the marker, linestyle, and color
plt.title('Your Plot Title')  # Replace 'Your Plot Title' with your actual title
plt.xlabel('X Axis Label')  # Replace 'X Axis Label' with your actual x-axis label
plt.ylabel('Y Axis Label')  # Replace 'Y Axis Label' with your actual y-axis label
plt.grid(True)  # Optional: Adds a grid
plt.show()