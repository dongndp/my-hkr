#!/bin/python3
# https://www.hackerrank.com/challenges/py-if-else/problem
# Python If-Else

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    N = int(input())
    if N % 2 == 1:
        print("Weird")
    elif N in range(6,21):
        print("Weird")
    else:
        print("Not Weird")
