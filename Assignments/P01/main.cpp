/*****************************************************************************
*                    
*  Author:           Victor Marchesi
*  Email:            vzmarchesi1016@my.msutexas.edu
*  Label:            04-P01
*  Title:            Vector Class
*  Course:           2143-201
*  Semester:         Spring 2023
* 
*  Description:
*        Writing a vector class implementing 4 constructors some overloaded
*        to accept arrays, vectors, and data from an input file. Also
*        implement 10 methods which each push or pop info, based on the
*        the paramaters passsed in.
* 
*  Usage:
*        Test code is provided in main() and should run without any issues
*        NOTE: MY pushFront and pushRear methods aren't working
* 
*  Files: 
*        input.dat
*        input1.dat
*        input2.dat
*        input3.dat
*        test.out
*****************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;


struct Node //struct Node
{
  int data;
  Node *next;
  Node *prev;

  Node(int num) //struct constructor
  {
    data = num;
    next = NULL;
    prev = NULL;
  }
};

/*
 * Class Vector
 * 
 * Description:
 *      The class is vector so it works like a linked list to
 *      push, pop, and add in orderdepending on the methods
 *      called in main()
 * 
 * Public Methods:
 *      - Vector() : constructor that creates the default vector with 
 *        an empty Node
 *      - Vector(int arr[], int size) : constructor that creates
 *        a vector with array input and size of the rray input
 *      - Vector(string fileName) : constructor that creates a vector
 *        using ifstream input filename and opens an ifstream with
 *        the string name of the file
 *      - Vector(Vector &V1) : constructor that creates a vector from
 *        a given vector
 *      - void pushFront(int val) : adds single value to front of this.list
 *      - void pushFront(Vector V2): adds entire other.list to front of 
 *        this.list
 *      - void pushRear(int val) : adds single value to rear of this.list
 *      - void pushRear(Vector V2) : adds entire other.list to rear of 
 *        this.list
 *      - void pushAt(int loc,int val)
 *      - void inOrderPush(int val) : adds single value to proper location in 
 *        order to maintain order (ascending or descending)
 *      - int popFront() : removes single value from front of list
 *      - int popRear() : removes single value from rear of list
 *      - int popAt(int loc) : removes single value from an indexed location
 *        if index between 0 and size of           
 *      - int find(int val) : find location of item (index) if it exists
 * 
 * Private Methods:
 *      - Creates a "Node * head" that initializes the node to be used by
 *        the methods later
 * 
 * Usage: 
 * 
 *      - You can call any method after you create a class using
 *        one of the constructors for the reason you need. Currently
 *        you can create a Vector using arrays, input files, other
 *        vectors, and just creating a vector from scratch using
 *        the "Vector name" syntax. If you want to use parameters
 *        use "Vector name(input parameters)" syntax.
 *      
 */
class Vector
{
  private:
  Node * head;

  public:
/***********************CONSTRUCTORS*****************************/
  /*
   * Public : Vector()
   * 
   * Description:
   *      - Constructor that creates a default vector
   * 
   * Params:
   *      - No parameters
   * 
   * Returns:
   *      - returns nothing
   */
  Vector()
  {
    head = NULL;
  }

  /*
   * Public : Vector()
   * 
   * Description:
   *      - Constructor that creates a method based on the array name
   *        and size that is passed in
   * 
   * Params:
   *      - array[] name : array name to be read into a vector
   *      - int size of the array : size of the array for the for loop
   * 
   * Returns:
   *      - returns nothing
   */
  Vector(int arr[], int size)
  {
    head = NULL;
    Node * traverse = head;
    
    int num;
    Node * temp = new Node(num);
    
    for(int i = 0; i < size; i++)
    {
      Node * temp = new Node(num);
      pushRear(arr[i]);
    }
  }

  /*
   * Public : Vector()
   * 
   * Description:
   *      - Constructor that creates a vector from data from an
   *        file name string fileName
   * 
   * Params:
   *      - string fileName : file name to open the data to push into
   *                          the new vector
   * 
   * Returns:
   *      - returns nothing
   */
  Vector(string fileName)
  {
    head = NULL;
    
    ifstream fin;
    fin.open(fileName);

    Node * traverse = head;
    int temp;
  
    while(!fin.eof())
    {
      fin >> temp;
      pushRear(temp);
    }

    fin.close();
  }

  /*
   * Public : Vector()
   * 
   * Description:
   *      - Constructor that creates a vector from data from an
   *        file name string fileName
   * 
   * Params:
   *      - Vector &V1 : passes vector by reference and adds
   *        the valus to a new vector
   * 
   * Returns:
   *      - nothing
   */
  Vector(Vector &V1)
  {
    head = NULL;
    Node * traverse = head;
    
    while(traverse)
    {
      pushRear(V1);
      traverse = traverse->prev;
    }
  }

/*****************************METHODS*******************************/
  /*
   * Public : pushFront
   * 
   * Description:
   *      - pushes int val to the front of the vector
   * 
   * Params:
   *      - int val : value to push to the front of the vector
   * 
   * Returns:
   *      - void function does not return anything
   */

  void pushFront(int val)
  {
    Node * temp = new Node(val);

    if(head == NULL)
    {
      head = temp;
    }

    else
    {
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
  }

  /****NOT WORKING*****
   * Public : pushFront
   * 
   * Description:
   *      - pushes Vector V1 to the front of a vector
   * 
   * Params:
   *      - Vector &V1 : vector to push to the front of the vector
   * 
   * Returns:
   *      - void function does not return anything
   */
  void pushFront(Vector &V1)
  {
    // Node * traverse = V1.head;
    

    // for(int i = 0; i < V1.getSize() - 1; i++)
    // {
    //   pushFront(traverse->data);
    // }
  }

  /*
   * Public : pushRear
   * 
   * Description:
   *      - pushes int val to the rear of a vector
   * 
   * Params:
   *      - int val : value to push to the rear of a vector
   * 
   * Returns:
   *      - void function does not return anything
   */
  void pushRear(int val)
  {
    Node * temp = new Node(val);
  
    if(head == NULL)
    {
      head = temp;
    }
      
    else
    {
      Node * traverse = head;
      
      while(traverse->next != NULL)
      {
        traverse = traverse->next;
      }
      temp->prev = traverse;
      traverse->next = temp;
    }

  }

   /****NOT WORKING*****
   * Public : pushRear
   * 
   * Description:
   *      - pushes Vector V1 to the rear of a vector
   * 
   * Params:
   *      - Vector &V1 : vector to push to rear
   * 
   * Returns:
   *      - void function does not return anything
   */
  void pushRear(Vector &V1)
  {
    
  }

  /*
   * Public : pushAt
   * 
   * Description:
   *      - pushes int val bases on the index location int loc
   * 
   * Params:
   *      - int loc : index location to traverse to
   *      - int val : value to push into the index location
   * 
   * Returns:
   *      - void function does not return anything
   */
  void pushAt(int loc, int val)
  {
    int indX = 0;

    Node * temp = new Node(val);

    if(head == NULL)
    {
      head = temp;
    }

    else
    {
      Node * traverse = head;
      
      while(indX != loc - 1)
      {
        traverse = traverse->next;
        indX++;
      }
      temp->next = traverse->next;
      temp->prev = traverse;
      traverse->next = temp;
    }
  }

  /*
   * Public : inOrderPush
   * 
   * Description:
   *      - pushes a value based on the order of the contents of
   *        the vector
   * 
   * Params:
   *      - int val : value that will be pushed into vector
   * 
   * Returns:
   *      - void function does not return anything
   */
  void inOrderPush(int val) 
  {
    Node * temp = new Node(val);

    if (head == NULL)
      head = temp;

    else if (temp->data < head->data)
      pushFront(val);

    else 
    {
      Node * traverse = head;
      while(traverse->next && traverse->next->data < temp->data)
        traverse = traverse->next;

      if(traverse->next == NULL)
      {
        pushRear(val);
      }
        
      else
      {
        temp->next = traverse->next;
        traverse->next = temp;
        temp->prev = traverse;
        temp->next->prev = temp;
      }
    }
  }

  /*
   * Public : popFront
   * 
   * Description:
   *      - pops off the first index value off the vector and returns the
   *        result as an integer
   * 
   * Params:
   *      - none
   * 
   * Returns:
   *      - returns and integer of what was stored in the index
   */
  int popFront()
  {
    Node * temp = head;

    head = head->next;
    return head->data;
    
    delete temp;
  }

  /*
   * Public : popRear
   * 
   * Description:
   *      - pops off the last index value off the vector and returns the
   *        result as an integer
   * 
   * Params:
   *      - none
   * 
   * Returns:
   *      - returns and integer of what was stored in the index
   */
  int popRear()
  {
    Node * popRear = head;

    Node * traverse = head;
    while(traverse != NULL)
    {
      popRear = traverse->next;
      traverse = traverse->next;
    }
    return popRear->data;
    delete popRear;
    traverse->prev->next = NULL;
  }

  /*
   * Public : popAt
   * 
   * Description:
   *      - pops the value of the index at a specific location that
   *        is fed into the method
   * 
   * Params:
   *      - int loc : index location where to remove
   * 
   * Returns:
   *      - returns and integer of what was stored in the location
   */
  int popAt(int loc)
  {
    int indX = 0;
    Node * traverse = head;
    Node * temp = head;
    
    while(indX != loc)
    {
      traverse = traverse->next;
      temp = temp->next;
      indX++;
    }
    traverse->prev->next = temp->next;
    traverse->next->prev = traverse;

    return temp->data;
    delete temp;
  }

  /*
   * Public : find
   * 
   * Description:
   *      - finds the value that is passed into the method and returns
   *        its index location
   * 
   * Params:
   *      - int val : passes in the integer value of what needs to be found
   *        in the vector
   * 
   * Returns:
   *      - returns the integer index of where the value was found
   */
  int find(int val)
  {
    int indX = 0;
    Node * traverse = head;

    while(traverse != NULL)
    {
      traverse = traverse->next;
      indX++;
      
      if(val == traverse->data)
      {
        return indX;
      }
      else if(traverse->data != val)
      {
        return -1;
      }
    }
  }

  /*
   * Public : print
   * 
   * Description:
   *      - prints the vector results to the console and outfile
   * 
   * Params:
   *      - none
   * 
   * Returns:
   *      - void function does not return anything
   */
  void print()
  {
    Node * traverse = head;

    ofstream fout;
    fout.open("test.out", ios::app);

    fout << "[";
    cout << "[";
    
    while(traverse)
    {
      fout << traverse->data;
      cout << traverse->data;
      if(traverse->next != NULL)
      {
        fout << ", ";
        cout << ", ";
      }
      traverse = traverse->next;
    }
    fout << "]" << endl;
    cout << "]" << endl;

    fout.close();
  }
};
 
int main() 
{
  // Lines 556-558 is to clear test.out on each run of the program
  ofstream fout;
  fout.open("test.out");
  fout.close();

  //lines 561-565 print out the heading to the outfile test.out
  ofstream fout1;
  fout1.open("test.out", ios::app);
  fout1 << "Victor Marchesi" << endl;
  fout1 << "February 7, 2023" << endl;
  fout1 << "Spring 2143" << endl << endl;
  
  int x; // int x to be used later to save values into it
  
  Vector v1; // creation of a default Vector constructor
  v1.pushFront(18); // pushes 18 to the front of v1
  v1.pushFront(20); // pushes 20 to the front of v1
  v1.pushFront(25); // pushes 25 to the front of v1
  v1.pushRear(18);  // pushes 18 to the rear of v1
  v1.pushRear(20);  // pushes 20 to the rear of v1
  v1.pushRear(25);  // pushes 25 to the rear of v1
  v1.print();       // prints v1 vector
  // [25, 20, 18, 18, 20, 25]
  
  int arr[] = {11,25,33,47,51}; //init list of array arr[]
  Vector v2(arr, 5);         //creating a Vector from the array value and size
  v2.print();                // prints v2 vector
  // [11, 25, 33, 47, 51]
  
  v2.pushFront(9);    // pushes 9 to the front of v2
  v2.inOrderPush(27); // pushes 18 to the front of v1
  v2.pushRear(63);    // pushes 18 to the front of v1
  v2.print();         // prints v2 Vector
  // [9, 11, 25, 27, 33, 47, 51, 63]
  
  v1.pushRear(v2);
  v1.print();
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]
  
  x = v1.popFront(); //pops the front value of v1 and store in it x
  x = v1.popFront(); //pops the front value of v1 and store in it x
  x = v1.popFront(); //pops the front value of v1 and store in it x
  v1.print();        //prints v1 vector
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  fout << x << endl;
  // 18
  
  x = v1.popRear(); //pops the rear value of v1 and store in it x
  x = v1.popRear(); //pops the rear value of v1 and store in it x
  x = v1.popRear(); //pops the rear value of v1 and store in it x
  v1.print();       //prints v1 vector
  // [18, 20, 25, 9, 11, 25, 27, 33]
  fout << x << endl; //prints out x to the outfile
  // 47
  
  x = v2.popAt(3); // pops the value in index 3 and saves it in int x
  v2.print(); //prints v2 vector
  // [9, 11, 25, 33, 47, 51, 63]
  fout << x << endl;
  // 27

  //looks for the value 51 in the vector v2 and saves the index in int x
  x = v2.find(51);
  fout << x << endl; // prints out the index of where 51 is stored
  // 5

  //looks for the value 99 in the vector v2 and saves the index in int x
  x = v2.find(99);
  fout << x << endl; //prints out -1 because the item was not found
  // -1

  // Vector constructor creating a vector from an existing vector
  Vector v3(v1);
  v3.print();    // prints out vector v3
  // [18, 20, 25, 9, 11, 25, 27, 33]
  
  v3.pushFront(v2);  //pushes vector v2 to the fron of vector v3
  v3.print();        //prints vector v3
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  // creates a vector from the input data from "input.dat"
  Vector v4("input.dat");
  v4.pushRear(v3); // pushes the existing vector v3 to the rear of v4
  v4.print();      // prints out vector v4
  /* [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23,
      18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25,
      33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]*/
  fout1.close();
  fout.close(); // closing the outfile
  return 0;     // closing the program
}