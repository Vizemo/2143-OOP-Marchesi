'''
  Author:           Victor Marchesi
  Email:            vzmarchesi1016@my.msutexas.edu
  Label:            09-P04
  Title:            Roll them Bones!
  Course:           2143-201
  Semester:         Spring 2023
 
  Description:
        Use 2 classes to create a dice roller with different parameters
        depending on what kind of die and how many sides
        
  Usage:
        Test code is provided in main and should run without any 
        issues
 
  Files: 
        main.cpp    : Main driver file
        output.txt  : Output data that comes from main
        BANNER.cpp  : My banner
'''

import sys
from rich import print
import random


'''
  Class Die
 
  Description:
      - Creates a die with different methods with their own description
 
  Public Methods:
      - def __init__(self, sides=None):
      - def roll(self):
 
  Usage: 
      - use is to create a Die objects
'''
class Die(object):

#*************************constructors*******************

  '''
    Public : __init__(self, sides=None):
    
    Description:
         - Constructor that creates a default Dice
    
    Params:
         - self
         - sides=None
    
    Returns:
        - returns nothing
  '''
  def __init__(self, sides=None):
    if not sides:
      self.sides = 6

    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides
      
  def __str__(self):
    return f"[sides: {self.sides}]"
      
#*************************methods************************
  '''
  Public : roll(self):
    
    Description:
         - rolls the die or dice
    
    Params:
         - self
    
    Returns:
        - returns value of the roll
  '''
  def roll(self):
    values = [x for x in range(self.sides)]

    random.shuffle(values)

    return values[0] + 1


'''
  Class Dice
 
  Description:
      - Creates a die with different methods with their own description
 
  Public Methods:
      - def __init__(self, sides=None, num_dice=1):
      - def sum(self):
      - def max(self):
      - def min(self):
      - def avg(self):
 
  Usage: 
      - use is to create a Dice objects
'''
class Dice:
#*************************constructors*******************
  '''
    Public : __init__(self, sides=None, num_dice=1):
    
    Description:
         - Creates a dice object bases on the parameters passed in
    
    Params:
         - self
         - sides=None
         - num_dice=1
    
    Returns:
        - returns value of the roll
  '''

  def __init__(self, sides=None, num_dice=1):
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()
    elif isinstance(sides, str):
      rolls = sides.split('.')
      num_dice, sides = int(rolls[0]), int(rolls[2])
      
    self.sides = sides

    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

#*************************methods************************
  '''
    Public : sum(self):
    
    Description:
         - finds the sum of the rolls of the dice object 
           that is passed in
    
    Params:
         - self
    
    Returns:
        - returns sum of the rolls
  '''
  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()
      
    return total
    
  '''
    Public : max(self):
    
    Description:
         - finds the maximum roll of the dice object that is passed in
    
    Params:
         - self
    
    Returns:
        - returns max of the rolls
  '''
  def max(self):
    max = 0
    for d in self.dice:
      roll = d.roll()
      if max <= roll:
        max = roll

    return max

  '''
    Public : min(self):
    
    Description:
         - finds the minimum roll of the dice object that is passed in
    
    Params:
         - self
    
    Returns:
        - returns min of the rolls
  '''
  def min(self):
    min = 0
    flag = 0
    for d in self.dice:
      roll = d.roll()
      if flag == 0:
        min = roll
        flag += 1
      elif min >= roll:
        min = roll

    return min

  '''
    Public : avg(self):
    
    Description:
         - finds the average roll of the dice object that is passed in
    
    Params:
         - self
    
    Returns:
        - returns avg of the rolls
  '''
  def avg(self):
    avg = 0
    count = 0
    for d in self.dice:
      avg += d.roll()
      count += 1
    return avg // count

  '''
    Public : roll(self, rollType=None):
    
    Description:
         - chooses what method to run based on the input
           max, min, avg, and sum
    
    Params:
         - self
         - rollType=None
    
    Returns:
        - returns whatever method is called bases on the input
  '''
  def roll(self, rollType=None):
    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()


#Main where the methods are called
if __name__ == '__main__':
  #Creates a dice Object
  d1 = Dice(10, 5)

  #Method calls to
  dieTester(d1, 10, "sum")
  dieTester(d1, 10, "max")
  dieTester(d1, 10, "min")
  dieTester(d1, 10, "avg")
