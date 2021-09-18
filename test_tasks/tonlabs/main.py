def is_bracket(s: str) -> bool:
    return s in ['[', ']', '{', '}', '(', ')']


def is_open_bracket(s: str) -> bool:
    return s in ['[', '{', '(']


def is_close_bracket(s: str) -> bool:
    return s in [']', '}', ')']


def is_annihilation(f_s: str, s_s: str) -> bool:
    """
    Is pair of brackets correct?

    :param f_s: first bracket
    :param s_s: second bracket
    :return: is annihilation brackets
    """
    if f_s == '(':
        return s_s == ')'
    if f_s == '[':
        return s_s == ']'
    if f_s == '{':
        return s_s == '}'


def is_infinite(s: str) -> bool:
    """
    Is substring of a sequence of string 's' is infinite?

    :param s:
    :return:
    """
    stack = []

    for letter in s:
        if is_bracket(letter):
            if stack and is_annihilation(stack[-1], letter):
                stack.pop()
            else:
                stack.append(letter)

    if len(stack) % 2 == 0:
        start = 0
        end = len(stack) - 1
        while start < end:
            if not is_annihilation(stack[end], stack[start]):
                return False
            start += 1
            end -= 1

        return True
    return False


def find_substring(s: str) -> str:
    """
    Find max substring of infinite concateneted strings of input string 's',
    in addition output substring must contain the correct sequence of parentheses.

    :param s: input string contain all latin letters and parentheses '(){}[]'.
    :return str: max substring.
    """
    if len(s) == 0:
        return ""

    if is_infinite(s):
        return "Infinite"

    stack = []
    max_substring = ''
    substring = ''
    d_s = s + s

    for i in range(len(d_s)):
        letter = d_s[i]

        if is_bracket(letter):
            if is_open_bracket(letter):
                stack.append((letter, len(substring)))
                substring += letter
            elif is_close_bracket(letter) and stack and is_annihilation(stack[-1][0], letter):
                stack.pop()
                substring += letter
            else:
                max_substring = helper(stack, substring, max_substring)
                substring = ''
                stack = []
                if i > len(s):
                    break
        else:
            substring += letter

    max_substring = helper(stack, substring, max_substring)
    return max_substring


def helper(stack, substring, max_substring):
    """
    Handles the case when an open bracket is in a substring and
    find max substring with the correct sequence of parentheses.

    :param stack: stack of non closed brackets.
    :param substring: substring of a sequence of 's'.
    :param max_substring: current max substring.
    :return: new max substring.
    """
    if stack:
        start = 0

        for j in range(len(stack)):
            bracket = stack[j]
            index = bracket[1]

            if j + 1 < len(stack):
                next_bracket = stack[j + 1]
                end = next_bracket[1]
            else:
                end = len(substring)

            first_part = substring[start:index]
            second_part = substring[index + 1:end]
            max_part = first_part if len(first_part) >= len(second_part) else second_part

            if len(max_substring) < len(max_part):
                max_substring = max_part

            start = index + 1
    elif len(max_substring) < len(substring):
        max_substring = substring

    return max_substring
