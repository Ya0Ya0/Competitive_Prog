start = -15
end = 10
step = 5

# Create a list of numbers from start to end with the given step
numbers = list(range(start, end + step, step))

# Convert the numbers to strings and join them with a space
output = ' '.join(map(str, numbers))

print(output)