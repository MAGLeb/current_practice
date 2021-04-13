from twitch import solution


def prepare_string(input_string):
    n, array, *string = input_string.strip().split()

    n = int(n[0])
    array = array.split(',')

    return n, array[0:-1], string


def test_1():
    n, array, string = prepare_string('1, cheer, roo100 big1000')

    actual = solution(n, array, string)
    expected = 'NO_CHEERS'

    assert actual == expected


def test_2():
    n, array, string = prepare_string('1, cheer, this is just a normal message and also cheer100 cheer100')

    actual = solution(n, array, string)
    expected = 'cheer200'

    assert actual == expected


def test_2():
    n, array, string = prepare_string('1, cheer, this is just a normal message and also cheer100 cheer100')

    actual = solution(n, array, string)
    expected = 'cheer200'

    assert actual == expected


def test_3():
    n, array, string = prepare_string('1, cheer, this is just a normal message,look at me')

    actual = solution(n, array, string)
    expected = 'NO_CHEERS'

    assert actual == expected


def test_4():
    n, array, string = prepare_string('1, cheer,party,rainbow, cheer1 cheer2, cheer4, party100 cheer1')

    actual = solution(n, array, string)
    expected = 'party100,cheer8'

    assert actual == expected


def test_5():
    n, array, string = prepare_string('1, cheer,party, cheer1 cheer2, cheer4,party100 cheer1')

    actual = solution(n, array, string)
    expected = 'party100,cheer8'

    assert actual == expected


def test_6():
    n, array, string = prepare_string('1, cheer, cheer10000 cheer10000 cheer10000 cheer10000 cheer10000 cheer10000 '
                                      'cheer10000 cheer10000 cheer10000 cheer10000 cheer1, cheer4')

    actual = solution(n, array, string)
    expected = 'cheer4'

    assert actual == expected


def test_7():
    n, array, string = prepare_string('1, cheer, cheer10000 cheer10000 cheer10000 cheer10000 cheer10000 cheer10000 '
                                      'cheer10000 cheer10000 cheer10000 cheer10000, cheer4')

    actual = solution(n, array, string)
    expected = 'cheer100004'

    assert actual == expected


def test_8():
    n, array, string = prepare_string('1, cheer, cheer1 cheer10001, cheer4')

    actual = solution(n, array, string)
    expected = 'cheer4'

    assert actual == expected


def test_9():
    n, array, string = prepare_string('1, cheer, cheer1 cheer10000, cheer4')

    actual = solution(n, array, string)
    expected = 'cheer10005'

    assert actual == expected


def test_10():
    n, array, string = prepare_string('3, cheer, cheer1 cheer2,cheer4')

    actual = solution(n, array, string)
    expected = 'cheer4'

    assert actual == expected


def test_11():
    n, array, string = prepare_string('1, party, cheer1')

    actual = solution(n, array, string)
    expected = 'NO_CHEERS'

    assert actual == expected


def test_12():
    n, array, string = prepare_string('1, cheer, cheer1 cheer2,cheer4')

    actual = solution(n, array, string)
    expected = 'cheer7'

    assert actual == expected
