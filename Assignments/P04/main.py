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

from Dice import Die
from Dice import Dice
from rich import print

'''
  Public : dieTester(die, runs=10, testType="sum"):
  
  Description:
       - Prints to the screen what is needed based on the input
         max, min, avg, and sum
  
  Params:
       - self
       - runs=10
       - testType="sum"
  
  Returns:
      - returns whatever method is called bases on the number
        of wanted runs and input for arithmetic
'''
def dieTester(die, runs=10, testType="sum"):
  if isinstance(die, Die):
    print(f"Testing {die.sides} sided die for {runs} rolls:")
    print("    [ ", end="")
    for i in range(runs):
      print(die.roll(), end=" ")
    print("]")
  else:
    print(f"Rolling {len(die.dice)} {die.sides} "
    f"sided die {runs} times to get the {testType} value:"
    )
    print("    [ ", end="")
    for i in range(runs):
      if testType == "avg":
        print(die.avg(), end=" ")
      elif testType == "min":
        print(die.min(), end=" ")
      elif testType == "max":
        print(die.max(), end=" ")
      else:
        print(die.sum(), end=" ")
    print("]")

#Main where the methods are called
if __name__ == '__main__':
  #Creates a dice Object
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)
  d4 = Dice("8.d.20")

  #Method calls to
  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
  dieTester(d4, 20, "max")
