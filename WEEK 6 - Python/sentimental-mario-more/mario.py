from cs50 import get_int

h = 0
while h < 1 or h > 8:
    h = get_int("Height: ")

for i in range(h):
    blank = " " * (h - 1 - i)
    s = "#" * (i + 1)
    print(f"{blank}{s}  {s}")
