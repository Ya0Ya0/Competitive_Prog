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
    cant = [[]]*len(words)
    words = sorted(words)
    for i in range(len(words)):
        for j in (i+1,len(words)):
            if(len(cant[j]) == 12):
                return cant[j]

            if(can_build_from(words[i],words[j])):
                cant[j] += words[j]
                
    return None

# Example usage
words_list = [
    'a', 'ab', 'abc', 'abcd', 'abcde', 'abcdef'
]

valid_sequence = find_valid_sequence(words_list)

if valid_sequence:
    print("A valid sequence is:", valid_sequence)
else:
    print("No valid sequence found.")