#!/usr/bin/python3
import re

with open('./input.list') as f:
    input=f.readlines()

ptOneScore = 0
ptTwoScore = 0

for line in input:
    #print(line)
    regex = re.compile('^(\d+)-(\d+),(\d+)-(\d+)$')
    matches = re.search(regex, line)

    firstElftemp = (matches.group(1), matches.group(2))
    secondElftemp = (matches.group(3), matches.group(4))


    firstElf = [int(x) for x in firstElftemp]
    secondElf = [int(x) for x in secondElftemp]


    


    if firstElf[0] <= secondElf[0] and firstElf[1] >= secondElf[1]:
        ptOneScore += 1
    elif secondElf[0] <= firstElf[0] and secondElf[1] >= firstElf[1]:
        ptOneScore += 1

    if firstElf[0] <= secondElf[1] and secondElf[0] <= firstElf[1]:
        ptTwoScore += 1

    
print(ptOneScore)
print(ptTwoScore)
    

