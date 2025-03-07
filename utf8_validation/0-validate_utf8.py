#!/usr/bin/python3
"""
Module for UTF-8 Validation

"""
from typing import List


def validUTF8(data: List[int]) -> bool:
    num_bytes = 0
    for byte in data:
        byte &= 0xFF
        if num_bytes == 0:
            if byte >> 7 == 0:  # 1-byte character
                continue
            elif byte >> 5 == 0b110:  # 2-byte character
                num_bytes = 1
            elif byte >> 4 == 0b1110:  # 3-byte character
                num_bytes = 2
            elif byte >> 3 == 0b11110:  # 4-byte character
                num_bytes = 3
            else:
                return False
        else:
            if byte >> 6 != 0b10:  # Continuation byte should start with '10'
                return False
            num_bytes -= 1
    return num_bytes == 0
