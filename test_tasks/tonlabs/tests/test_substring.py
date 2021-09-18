from main import find_substring


def test_start_end():
    input = "}](){"
    actual_output = "(){}"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_with_letters():
    input = "sh(dh)}"
    actual_output = "sh(dh)"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_infinite():
    input = "]h({hdb}b)["
    actual_output = "Infinite"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_infinite_second():
    input = "}a](w)[e{h({hdb}b)"
    actual_output = "Infinite"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_longest_substring():
    input = "}](w)]{h({hdb}b)"
    actual_output = "{h({hdb}b)}"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_with_open_bracket():
    input = "{()"
    actual_output = "()"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_with_open_bracket_2():
    input = "}[(2){()"
    actual_output = "(2){()}"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_with_close_bracket():
    input = "}())"
    actual_output = "()"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_empty():
    input = ""
    actual_output = ""
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_dummy():
    input = "{{{{{"
    actual_output = ""
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_dummy_2():
    input = "}}}}"
    actual_output = ""
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_with_same_substring_length():
    input = "[({e}[]3452)[qa(z)[({e}[])[qa(zpz{}[])}"
    actual_output = "({e}[]3452)"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_1():
    input = "}qwe]({e}[])[{"
    actual_output = "Infinite"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_2():
    input = "[({e}[])[qa(z)[({e}[])[qa(zpz{}[])}"
    actual_output = "qa(zpz{}[])"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_3():
    input = "[({e}[])[qa(z)}"
    actual_output = "({e}[])"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_4():
    input = "[({e}[])[qa(z)"
    actual_output = "({e}[])"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_5():
    input = "[({e}[])}[qa(z)}[({e}[])}[[[qa(zpz{}[])}"
    actual_output = "qa(zpz{}[])"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_6():
    input = "]]][({e}[])]}[qa(z)}[qa(zpz{}[])}[[[({e}[])"
    actual_output = "[[[({e}[])]]][({e}[])]"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_dummy_7():
    input = "}2){1}(({"
    actual_output = "({}2){1}"
    expected_output = find_substring(input)

    assert actual_output == expected_output


def test_dummy_8():
    input = "}}}}}}}}}}((((((((qwerqwerqwerqwer{}){"
    actual_output = "(qwerqwerqwerqwer{}){}"
    expected_output = find_substring(input)

    assert actual_output == expected_output
