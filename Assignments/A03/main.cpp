/*****************************************************************************
*                    
*  Author:           Victor Marchesi code credit to Dr.Griffin
*  Email:            vzmarchesi1016@my.msutexas.edu
*  Label:            A03
*  Title:            Linked List Class
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Instructions
*       
*   - This program does not require any non standard libraries 
*       
*  Purpose
*   - For this program, the main driver was used to test the CircularArrayQue class
*
*  Files:            
*       main.cpp    : driver program 
*****************************************************************************/
    
#include <iostream>

using namespace std;

/*****************************************************************************
 * Class name: CircularArrayQue
 * 
 * Description:
 *      For this program, the main driver was used to test the CircularArrayQue 
 *      class
 * 
 * Public Methods:
 *      - CircularArrayQue()
 *      - CircularArrayQue(int size)
 *      - void Push(int item)
 *      - int Pop()
 * 
 * Private Methods:
 *      - void init(int size = 0)
 *      - bool Full()
 * 
 * Usage: 
 * 
 *      - To create a circular class, and implement operator overloading with 
 *      - examples
 *  
 *      
 *****************************************************************************/

class CircularArrayQue {
private:
    int *Container;     //pointer to an int container
    int Front;          //int front created
    int Rear;           //int rear created
    int QueSize;        //int QueSize created
    int CurrentSize;    //int CurrentSize created

    /**
     * Private : init
     * 
     * Description:
     *      initializes front. rear and current size
     * 
     * Params:
     *      - int size = 0
     * 
     * Returns:
     *      - nothing
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private: full
     * 
     * Description:
     *      returns current size of quesize
     * 
     * Params:
     *      - none
     * 
     * Returns:
     *      - bool so true or false
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
     * Public: CircularArrayQue
     * 
     * Description:
     *      constructor which dynamically allocates 10 slots
     * 
     * Params:
     *      - none
     * 
     * Returns:
     *      - nothing
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
     * Public: CircularArrayQue
     * 
     * Description:
     *      constructor which dynamically allocates 10 slots base on size
     *      is a copy constructor
     * 
     * Params:
     *      - int size
     * 
     * Returns:
     *      - nothing
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public: Push
     * 
     * Description:
     *      Pushes an item the beginning of the circular queue
     * 
     * Params:
     *      - int item
     * 
     * Returns:
     *      - nothing at it is a void function
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public/: Pop
     * 
     * Description:
     *      Describe the functions purposeGets rid of the top item in 
     *      the circular queue
     * 
     * Params:
     *      - none
     * 
     * Returns:
     *      - int, what ever the top item of the circular queue was
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    //this allows the operator overloading without iostream getting angry
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

//operator overloading setup code
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    //created a circular queue
    CircularArrayQue C1(5);

        //examples that were commented out
    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

        //examples pushing data onto the ciruclar queue
    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
