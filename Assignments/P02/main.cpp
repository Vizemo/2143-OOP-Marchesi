/***********************************************************************
*                    
*  Author:           Victor Marchesi
*  Email:            vzmarchesi1016@my.msutexas.edu
*  Label:            04-P02
*  Title:            Vector Class
*  Course:           2143-201
*  Semester:         Spring 2023
* 
*  Description:
*        Writing a vector class implementing constructors with some 
*        overloaded to accept arrays, vectors, and data from an 
*        input file. Also implement 10 methods which each push or 
*        pop info, based on the the paramaters passsed in.
* 
*  Usage:
*        Test code is provided in main() and should run without any 
*        issues
* 
*  Files: 
*        main.cpp    : Main driver file
*        output.txt  : Output data that comes from main
*        BANNER.cpp  : My banner
***********************************************************************/

#include <iostream>
#include <fstream>
using namespace std;


/*
 * Struct : Node
 * 
 * Description:
 *      - Node for storing int data with a prev and next pointer
 * 
 * Params:
 *      - No parameters
 * 
 * Returns:
 *      - returns nothing
 */
struct Node
{
  int data;
  Node *next;
  Node *prev;

  /*
   * Public : Node()
   * 
   * Description:
   *      - Constructor that creates a default Node
   * 
   * Public Methods:
   *      - Node(int num) : cretes the default Node with
   *        next and prev pointers == to NULL
   * 
   * Usage:
   *      - USed to create a default Node to store data in a
   *        linked list
   */
  Node(int num)
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
 *      push, pop, and add in order depending on the methods
 *      called in main()
 *      Also includes overloaded operators like +, -, =, and ==
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
 *      - print() : prints out a vector to cout and outfile streams
 *      - friend ostream& operator<<(ostream& output, const Vector& V1) :
 *        over loads the cout operator stream to print out a vector
 *      - friend oftream& operator<<(oftream& outfile, const Vector& V1) :
 *        over loads the cout operator stream to print out a vector
 *      - int& operator[](const int x) : overloads the [] operation to
 *        return the value passed in between the brackets
 *      - Vector& operator=(const Vector &rhs) : overloads the = operator
 *        to set a vector equal to another vector
 *      - bool operator==(const Vector &rhs) : overloads the == operator
 *        to check equality of another vector and returns a bool
 *      - Vector operator+(const Vector &rhs) : overloads the addition
 *        operator to add the values of one vector another
 *      - Vector operator-(const Vector &rhs) : overloads the subtraction
 *        operator to subtract the values of one vector another
 *      - Vector operator*(const Vector &rhs) : overloads the multiplication
 *        operator to multiply the values of one vector another
 *      - Vector operator/(const Vector &rhs) : overloads the division
 *        operator to divide the values of one vector another
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
  int size;

  public:

/*************************CONSTRUCTORS*****************************/
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
    size = 0;
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
  Vector(int arr[], int _size)
  {
    head = NULL;
    size = 0;
    
    Node * traverse = head;

    int num;
    Node * temp = new Node(num);
    
    for(int i = 0; i < _size; i++)
    {
      Node * temp = new Node(num);
      pushRear(arr[i]);
      size++;
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
    size = 0;
    
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
    Node * traverse = V1.head;
    head = new Node(traverse->data);

    traverse = traverse->next;
    while(traverse)
    {
      pushRear(traverse->data);
      traverse = traverse->next;
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
      size++;
    }

    else
    {
      temp->next = head;
      head->prev = temp;
      head = temp;
      size++;
    }
  }

  /*
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
    Node * traverse = V1.head;
    

    while(traverse->next)
    {
      traverse = traverse->next;
    }

    while(traverse)
    {
      pushFront(traverse->data);
      traverse = traverse->prev;
    }
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
      size++;
    }
      
    else
    {
      Node * traverse = head;
      
      while(traverse->next != NULL)
      {
        traverse = traverse->next;
        size++;
      }
      temp->prev = traverse;
      traverse->next = temp;
    }
  }

   /*
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
    Node * traverse = V1.head;
    
    while(traverse)
    {
      pushRear(traverse->data);
      traverse = traverse->next;
    }
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
      size++;
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
      size++;
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
    { 
      head = temp;
      size++;
    }

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
        size++;
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

    size--;
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
    Node * traverse = head;
    int temp;
    
    while(traverse->next)
    {
      traverse = traverse->next;
    }
    temp = traverse->data;
    traverse->prev->next = NULL;
    size--;
    delete traverse;
    return temp;
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
    size--;
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

    while(traverse)
    {      
      if(val == traverse->data)
      {
        return indX;
      }
        
      else
      {
        traverse = traverse->next;
        indX++;
      }
    }
    return -1;
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
    fout.open("output.txt", ios::app);

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

  /*
   * Public : Overloaded ostream operator
   * 
   * Description:
   *      - prints the vector results to the console
   * 
   * Params:
   *      - output, data type stream
   *      - V1, Vector passed by reference
   * 
   * Returns:
   *      - returns the data to the console
   */
  friend ostream& operator<<(ostream& output, const Vector& V1)
  {
    Node * temp = V1.head;
    output << "[";
    
    while (temp != NULL)
    {
      output << temp->data;
      if (temp->next != NULL)
      {
        output << ", ";
      }
      temp = temp->next;
    }
    output << "]";
    return output;
  }

  /*
   * Public : Overloaded fstream operator
   * 
   * Description:
   *      - prints the vector results to the outfile
   * 
   * Params:
   *      - output, data type stream
   *      - V1, Vector passed by reference
   * 
   * Returns:
   *      - returns the data to the output file of choice
   */
  friend fstream& operator<<(fstream& outfile, const Vector& V1)
  {
    Node* temp = V1.head;
    outfile << "[";
    
    while (temp != NULL)
    {
      outfile << temp->data;
      if (temp->next != NULL)
      {
        outfile << ", ";
      }
      temp = temp->next;
    }
    outfile << "]";
    return outfile;
  }

  /*
   * Public : Overloaded bracket operator
   * 
   * Description:
   *      - returns the vector index results
   * 
   * Params:
   *      - const int x
   * 
   * Returns:
   *      - returns the index location of a value
   */
  int& operator[](const int x)
  {
    Node * traverse = head;
    int t = x;
    
    while(t--)
    {
      traverse = traverse->next;
    }
    return traverse->data;
  }

  /*
   * Public : Overloaded assignment operator
   * 
   * Description:
   *      - assigns a vector to another vector
   * 
   * Params:
   *      - const vector by reference
   * 
   * Returns:
   *      - sets the values of vector to equal the values
   *        of the input vector
   */
  Vector& operator=(const Vector &rhs)
  {
    if(this == &rhs)
    {
      return * this;
    }
  
    this->head = rhs.head;
  
    return * this;
  }

  /*
   * Public : Overloaded equality operator
   * 
   * Description:
   *      - checks for equality of two vectors
   * 
   * Params:
   *      - const vector by reference
   * 
   * Returns:
   *      - checks the values of vector for equality of
   *        the values of the input vector
   */
  bool operator==(const Vector &rhs)
  {
    Node * left;
    Node * right;

    left = this->head;
    right = rhs.head;

    while (left != NULL && right != NULL)
    {
      if (left->data == right->data)
      {
        left = left->next;
        right = right->next;
      }
      else
      {
        return 0;
      }
    }
    return 1;
  }

  /*
   * Public : Overloaded addition operator
   * 
   * Description:
   *      - adds the values of two vectors
   * 
   * Params:
   *      - const vector by reference
   * 
   * Returns:
   *      - adds the values of one vector
   *        to the values of another vector
   */
  Vector operator+(const Vector &rhs)
  {
    Vector V;
    Node * shorter;
    Node * longer;
    
    if (rhs.size <= this->size)
    {
      shorter = rhs.head;
      longer = this->head;
    } 
      
    else if (rhs.size > this->size)
    {
      longer = rhs.head;
      shorter = this->head;
    }

    while (shorter != NULL)
    {
      cout << shorter->data + longer->data << endl;
      V.pushRear(shorter->data + longer->data);
      shorter = shorter->next;
      longer = longer->next;
    }

    while(longer)
    {
      V.pushRear(longer->data);
        longer = longer->next;
    }
  return V;
  }

  /*
   * Public : Overloaded subtraction operator
   * 
   * Description:
   *      - subtract the values of two vectors
   * 
   * Params:
   *      - const vector by reference
   * 
   * Returns:
   *      - subtract the values of one vector
   *        to the values of another vector
   */
  Vector operator-(const Vector &rhs)
  {
    Vector V;
    Node * left;
    Node * right;

    left = this->head;
    right = rhs.head;
    

    while (left && right)
    {
      cout << left->data - right->data << endl;
      V.pushRear(left->data - right->data);
      left = left->next;
      right = right->next;
    }

    while(right)
    {
      V.pushRear(right->data);
      right = right->next;
    }

    while(left)
    {
      V.pushRear(left->data);
      left = left->next;
    }
  return V;
  }

  /*
   * Public : Overloaded multiplication operator
   * 
   * Description:
   *      - multiplies the values of two vectors
   * 
   * Params:
   *      - const vector by reference
   * 
   * Returns:
   *      - multiplies the values of one vector
   *        to the values of another vector
   */
  Vector operator*(const Vector &rhs)
  {
    Vector V;
    Node * shorter;
    Node * longer;
    
    if (rhs.size <= this->size)
    {
      shorter = rhs.head;
      longer = this->head;
    } 
      
    else if (rhs.size > this->size)
    {
      longer = rhs.head;
      shorter = this->head;
    }

    while (shorter != NULL)
    {
      cout << shorter->data * longer->data << endl;
      V.pushRear(shorter->data * longer->data);
      shorter = shorter->next;
      longer = longer->next;
    }

    while(longer)
    {
      V.pushRear(longer->data);
        longer = longer->next;
    }
  return V;
  }

 Vector operator/(const Vector &rhs)
  {
    Vector V;
    Node * left;
    Node * right;

    left = this->head;
    right = rhs.head;
    

    while (left && right)
    {
      cout << left->data / right->data << endl;
      V.pushRear(left->data / right->data);
      left = left->next;
      right = right->next;
    }

    while(right)
    {
      V.pushRear(right->data);
      right = right->next;
    }

    while(left)
    {
      V.pushRear(left->data);
      left = left->next;
    }
  return V;
  }
};
 
int main() 
{
  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};
  
  Vector v1(a1,5);
  Vector v2(a2,3);
  
  ofstream fout;
  fout.open("output.txt");

  fout << "CMPS2143\nP02\nVictor Marchesi\n" << endl;
  
  cout << v1[2] << endl;
  // writes out 3
  
  v1[4] = 9;
  // v1 now = [1,2,3,4,9]
  
  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.
  fout << v1 << endl << endl;
  // writes out [1,2,3,4,9] to your output file.
  
  Vector v3;
  v3 = v1 + v2;
  fout << v3 << endl << endl;
  // writes out [11,22,33,4,9] to console.
  
  v3 = v1 - v2;
  cout << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console.
  fout << v3 << endl << endl;
  // writes out [-9,-18,-27,4,9] to outfile.
  
  v3 = v2 - v1;
  cout << v3 << endl;
  // writes out [9,18,27,4,9] to console.
  fout << v3 << endl << endl;
  // writes out [9,18,27,4,9] to outfile.

  v3 = v2 * v1;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.
  fout << v3 << endl << endl;
  // writes out [10,40,90,4,9] to outfile.

  v3 = v1 * v2;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.
  fout << v3 << endl << endl;
  // writes out [10,40,90,4,9] to outfile.

  v3 = v1 / v2;
  cout << v3 << endl;
  // writes out [0,0,0,4,9] to console.
  fout << v3 << endl << endl;
  // writes out [0,0,0,4,9] to outfile.
  
  v3 = v2 / v1;
  cout << v3 << endl;
  // writes out [10,10,10,4,9] to console.
  fout << v3 << endl << endl;
  // writes out [10,10,10,4,9] to outfile.
  
  cout << (v2 == v1) << endl;
  // writes 0 to console (false).
  fout << (v2 == v1) << endl << endl;
  // writes 0 to outfile (false).
  
  Vector v4 = v1;
  cout << (v4 == v1) << endl;
  // writes 1 to console (true).
  fout << (v4 == v1) << endl << endl;
  // writes 1 to outfile (true).

  fout.close();
  return 0; // closing the program
}