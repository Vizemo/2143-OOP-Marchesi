## P04 - Graphviz class
### Victor Marchesi
### Description:

-Creating a dice roller that rolls given amounts

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|   1   | [BANNER.cpp](./BANNER.cpp) | My Banner. |
|   2   | [main.cpp](./main.cpp)   | The source code for Graphviz class assignment. |
|   3   | [output.txt](./output.txt) | output.txt file that has the output data |


### Instructions

- This program requires importing rich(print), sys, and random

### Example Command

-D1 = Dice(10, 5)
  First parameter is number of sides, and second parameter is number of dices wanted

-dieTester(d1, 10, "sum")
  Parameter 1 is the Dice object
  Parameter 2 is the amount of times you want to roll
  Parameter 3 is the string name of what you want to do
  will roll the given amount times and find the sum of all rolls
  
-dieTester(d1, 10, "max")
  Parameter 1 is the Dice object
  Parameter 2 is the amount of times you want to roll
  Parameter 3 is the string name of what you want to do
  will roll the given amount times and find the maximum of all rolls
  
-dieTester(d1, 10, "min")
  Parameter 1 is the Dice object
  Parameter 2 is the amount of times you want to roll
  Parameter 3 is the string name of what you want to do
  will roll the given amount times and find the minimum of all rolls
  
-dieTester(d1, 10, "avg")
  Parameter 1 is the Dice object
  Parameter 2 is the amount of times you want to roll
  Parameter 3 is the string name of what you want to do
  will roll the given amount times and find the average of all rolls
