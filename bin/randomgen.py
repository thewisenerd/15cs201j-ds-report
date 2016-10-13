#!/usr/bin/env python3

from random import sample
import sys

f = 1
t = 100
n = 1

def getN(s):
  try:
    t = int(s)
    return t
  except:
    pass
  return None

for arg in sys.argv:
  if (len(arg) > 2):
    flag = arg[0:2]
    if (flag == "-f"):
      tmp = getN(arg[2:])
      if (tmp != None):
        f = tmp
    if (flag == "-t"):
      tmp = getN(arg[2:])
      if (tmp != None):
        t = tmp
    if (flag == "-n"):
      tmp = getN(arg[2:])
      if (tmp != None):
        if (tmp > 0):
          n = tmp

if (f > t):
  f, t = t, f

try:
  a = sample(range(f, t), n)
  a = [str(x) for x in a]
  print(", ".join(a))
except ValueError:
  print('Sample size exceeded population size.')
