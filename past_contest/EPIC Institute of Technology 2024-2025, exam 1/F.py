def read_file_to_list(filename):
    """Reads a text file and saves each line into a list."""
    lines = []
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()  # Read all lines into a list
    except FileNotFoundError:
        print(f"Error: The file '{filename}' was not found.")
    except IOError:
        print(f"Error: Could not read the file '{filename}'.")
    return [line.strip() for line in lines]  # Strip newline characters from each line

# Example usage
filename = 'example.txt'  # Replace with your file name
lines_list = read_file_to_list("10000-english-no-swears.txt")

from itertools import permutations
from collections import Counter

def can_build_from(word_a, word_b):
    """
    Check if word_a can be built from word_b.
    """
    count_a = Counter(word_a)
    count_b = Counter(word_b)
    
    # Check if word_b contains at least as many of each character as word_a requires
    for char, count in count_a.items():
        if count_b[char] < count:
            return False
    return True

def validate_sequence(words):
    """
    Validate if each word in the list can be built from the next word.
    """
    for i in range(len(words) - 1):
        if not can_build_from(words[i], words[i + 1]):
            return False
    return True

def find_valid_sequence(words):
    """
    Find a valid sequence of words that satisfies the constraints.
    """
    cant = []
    words = sorted(words)
    for i in range(len(words)):
            cant.append([words[i]])
    z = len(words)-2
    for i in range(z):        
        for j in (i+1,z): 
            if(can_build_from(words[i],words[j])):
                cant[j] += words[j]
        if(len(cant[j]) >= 12):
                return cant[j]
                
    return None

# Example usage


valid_sequence = find_valid_sequence(lines_list)

if valid_sequence:
    print("A valid sequence is:", valid_sequence)
else:
    print("No valid sequence found.")
# Print the list of lines
print(lines_list)