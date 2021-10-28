# -*- coding: utf-8 -*-
"""
Created on Thu Oct 28 19:27:33 2021

@author: ibayp
"""

"""
Based on Hacker Rank 30 days of code Challenge (day 10). Counting consecutive
'1' in a given binary number
"""
def countConsecutive(num):
    binary = bin(num).replace("0b", "")
    maximum = 0
    count = 0
    for x in binary:
        if x == '1':
            count += 1
            if count > maximum:
                maximum = count
        else:
            count = 0   
    return maximum

if __name__ == '__main__':
    n = int(input().strip())
    
    print(countConsecutive(n))
    
    