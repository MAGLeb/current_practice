from F_input import dictionaries

import sys
import requests
import argparse

FILE_NAME = 'truth.csv'


def create_parser():
    parser = argparse.ArgumentParser()
    parser.add_argument('host')
    parser.add_argument('port')
    parser.add_argument('--not_mult', type=int)
    parser.add_argument('--smallest', type=int)

    return parser


def check_args(namespace):
    if len(namespace) < 2:
        print("Error. Minimum 2 params.")
        sys.exit(1)


def make_request(host: int, port: int) -> dict:
    dictionary = {}
    response = requests.get(f'http://{host}:{port}')
    dictionaries = response.json()

    for dict_ in dictionaries:
        for key, list_values in dict_.items():
            if key in dictionary:
                dictionary[key] += list_values
            else:
                dictionary[key] = list_values

    return dictionary


parser = create_parser()
namespace = parser.parse_args(sys.argv[1:]).__dict__
check_args(namespace)

host, port = namespace['host'], namespace['port']
multiple, smallest = 100, 0

if namespace['not_mult'] is not None:
    multiple = namespace['not_mult']
if namespace['smallest'] is not None:
    smallest = namespace['smallest']

dictionary = make_request(host, port)

with open(FILE_NAME, 'w') as f:
    for key in sorted(dictionary):
        value = list(filter(lambda x: x >= smallest and x % multiple != 0, dictionary[key]))
        sum_ = sum(value)
        mean_ = sum_ / len(value)
        line = f'{key};{max(value)};{min(value)};{mean_:.2f};{sum_}'
        f.write(line + '\n')
