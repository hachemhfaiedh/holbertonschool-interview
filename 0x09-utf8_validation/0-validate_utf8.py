#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    bytes_number = 0
    for intg in data:
        bin = format(intg, '#010b')[-8:]
        if bytes_number == 0:
            for bit in bin:
                if bit == "0":
                    break
                bytes_number += 1

            if bytes_number == 0:
                continue

            if bytes_number > 4 or bytes_number == 1:
                return False
        else:
            if bin[0] != "1" or bin[1] != "0":
                return False

        bytes_number -= 1

    return bytes_number == 0
