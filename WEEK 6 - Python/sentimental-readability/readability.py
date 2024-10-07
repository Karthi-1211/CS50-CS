from cs50 import get_string


def main():
    text = get_string("Text: ")
    index = calculate(text)
    print_grade(index)


def calculate(s):
    letters, words, sentences = 0, 1, 0
    for i in range(len(s)):
        if s[i].isalpha():
            letters += 1
        elif s[i].isspace():
            words += 1
        elif s[i] in ['.', '!', '?']:
            sentences += 1

    L = letters / words * 100
    S = sentences / words * 100
    return round(0.0588 * L - 0.296 * S - 15.8)


def print_grade(n):
    if n < 1:
        print("Before Grade 1")
    elif n >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {n}")


main()
