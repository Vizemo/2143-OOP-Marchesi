from Dice import *

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