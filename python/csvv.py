import pandas as pd

def find_highest_sales_month(csv_data):
    """
    This function takes a CSV of sales data as input and returns the month with the highest sales.

    Parameters:
        csv_data (str or pd.DataFrame): The sales data can be passed as a string representing a CSV file or as a Pandas DataFrame.

    Returns:
        str: The month with the highest sales.
    """

    # Check if the input is a string representing a CSV file
    if isinstance(csv_data, str):
        # If it is a string, read the CSV file into a Pandas DataFrame
        df = pd.read_csv(csv_data)
    elif isinstance(csv_data, pd.DataFrame):
        # If it is already a Pandas DataFrame, use it directly
        df = csv_data
    else:
        raise ValueError("Invalid input type. Please provide a string or a Pandas DataFrame.")

    # Convert the 'Month' column to lowercase to ensure case-insensitive comparison
    df['Month'] = df['Month'].str.lower()

    # Set the 'Month' column as the index to make it easier to group by month
    df = df.set_index('Month')

    # Calculate the total sales for each month using the 'Sales' column
    total_sales = df['Sales'].sum()

    # Find the month with the highest sales
    highest_sales_month = total_sales.idxmax()

    return highest_sales_month

# Example usage with mock CSV data as a string
csv_data_string=pd.read_csv = """
Month,Sales
January,100
February,150
March,200
April,120
May,180
June,250
July,140
August,160
September,220
October,190
November,210
December,170
"""

highest_sales_month = find_highest_sales_month(csv_data_string)
print("Month with the highest sales:", highest_sales_month)  # Output: Month with the highest sales: June
                  