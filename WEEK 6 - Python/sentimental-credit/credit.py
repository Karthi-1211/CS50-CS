from cs50 import get_string


def main():
    num = get_string("Number: ")
    if check_valid(num):
        print_brand(num)
    else:
        print("INVALID")


def check_valid(n):
    if len(n) in [13, 15, 16] and check_sum(n):
        return True
    return False


def check_sum(n):
    sum = 0
    for i, c in enumerate(reversed(n)):
        if i % 2 == 0:
            sum += int(c)
        else:
            for j in str(int(c) * 2):
                sum += int(j)

    if sum % 10 == 0:
        return True
    return False


def print_brand(n):
    if len(n) == 15 and n[:2] in ["34", "37"]:
        print("AMEX")
    elif len(n) == 16 and n[:2] in ["51", "52", "53", "54", "55"]:
        print("MASTERCARD")
    elif (len(n) == 13 or len(n) == 16) and n[0] == '4':
        print("VISA")
    else:
        print("INVALID")


main()
