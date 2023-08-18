# TODO

from cs50 import get_int

# Setting parameters for height of triangle
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break
# Building actual pyramid
for i in range(0, n, 1):
    for j in range(0, n, 1):
        if (i+j < n-1):
            print(" ", end="")
        else:
            print("#", end="")
    print()