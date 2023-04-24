## P04 - Graphviz class
### Victor Marchesi
### Description:

-Creating a dice roller that rolls given amounts

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|   1   | [BANNER.cpp](./BANNER.cpp) | My Banner. |
|   2   | [main.py](./main.cpp)   | The source code to create objects for dice class assignment. |
|   3   | [Dice.py](./Dice.py)    | The source code for implementing the dice class assignment. |


### Instructions

- This program requires importing rich(print), sys, and random, and Dice/Die

### Example Command

D1 = Dice(10, 5)<br />
  -Creates a die with parameter<br />
  -First parameter is number of sides, and second parameter is number of dices wanted<br /><br />

dieTester(d1, 10, "sum")<br />
  -Parameter 1 is the Dice object<br />
  -Parameter 2 is the amount of times you want to roll<br />
  -Parameter 3 is the string name of what you want to do<br />
  -will roll the given amount times and find the sum of all rolls<br /><br />
  
dieTester(d1, 10, "max")<br />
  -Parameter 1 is the Dice object<br />
  -Parameter 2 is the amount of times you want to roll<br />
  -Parameter 3 is the string name of what you want to do<br />
  -will roll the given amount times and find the maximum of all rolls<br /><br />
  
dieTester(d1, 10, "min")<br />
  -Parameter 1 is the Dice object<br />
  -Parameter 2 is the amount of times you want to roll<br />
  -Parameter 3 is the string name of what you want to do<br />
  -will roll the given amount times and find the minimum of all rolls<br /><br />
  
dieTester(d1, 10, "avg")<br />
  -Parameter 1 is the Dice object<br />
  -Parameter 2 is the amount of times you want to roll<br />
  -Parameter 3 is the string name of what you want to do<br />
  -will roll the given amount times and find the average of all rolls<br />
