import math

def smaller_pieces(x):
    # The  number of slices that are bigger will be the power of 2 just smaller than or equal to X
    max_slices = 2**(math.log(x,2) )
    # The answer is the total of slices minus the number of big/equal slices multiplied by two
    ans = x-max_slices
    return ans*2

X = int(input("Enter the number of slices you want: "))
if X%2 != 0:
    print("Invalid Input. Please enter an even number.")
else:
   print(smaller_pieces(X))