## A04

- Name: Victor Marchesi
- Date: 02 Feb 2023
- Class: 2143 OOP

## Link to wiki
https://github.com/Vizemo/2143-OOP-Marchesi/wiki

## OOP TOPICS


## Abstraction

>![Abstraction](https://user-images.githubusercontent.com/91359207/215235472-b35ead28-9365-439f-aaf9-a85256c1a963.png)

## Definition
Data abstraction is one of the most essential and important features of object-oriented programming in C++. Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation. 
> https://www.geeksforgeeks.org/abstraction-in-cpp/
<br>


## Attributes / Properties

>![access_specifier](https://user-images.githubusercontent.com/91359207/215235502-d77cea35-c331-4b4d-a523-82d16ceb8ce8.png)

## Definition
In computing, the term attribute is used in many different contexts. In the context of a file system, it refers to a characteristic of a file in that system. So, a particular file can have a read-only attribute, which means it is write protected and can't be changed. Another file may not have this attribute, so a person or an application can both read and write to it.
> https://www.techtarget.com/whatis/definition/attribute
<br>


## Class

>![Class](https://user-images.githubusercontent.com/91359207/215235867-c1ea8a54-0ed7-4954-84c6-d2ed72f51eff.png)

## Definition
The building block of C++ that leads to Object-Oriented programming is a Class. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object. For Example: Consider the Class of Cars. There may be many cars with different names and brands but all of them will share some common properties like all of them will have 4 wheels, Speed Limit, Mileage range, etc. So here, the Car is the class, and wheels, speed limits, and mileage are their properties.
> https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/#
<br>


## Class Variable

> ![Class Variable](https://user-images.githubusercontent.com/91359207/215235591-46138041-750f-4498-830c-437dec19594f.png)

## Definition
Class variables also known as static variables are declared with the static keyword in a class, but outside a method, constructor or a block. There would only be one copy of each class variable per class, regardless of how many objects are created from it
> https://www.tutorialspoint.com/What-are-class-variables-instance-variables-and-local-variables-in-Java
<br>


## Composition

>![Composition](https://user-images.githubusercontent.com/91359207/215235625-335f0727-7d34-4bc0-bb44-73ee7083890e.png)

## Definition
Composition is one of the fundamental concepts in object-oriented programming. It describes a class that references one or more objects of other classes in instance variables. This allows you to model a has-a association between objects.
> https://stackify.com/oop-concepts-composition/
<br>


## Constructor

>![Constructor](https://user-images.githubusercontent.com/91359207/215235665-2e5d8363-b945-4408-9e3f-e2da5fea3200.png)

## Definition
Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure. Constructor is invoked at the time of object creation. It constructs the values i.e. provides data for the object which is why it is known as constructors.
> https://www.geeksforgeeks.org/constructors-c/
<br>


## Destructor

>![Screenshot 2023-04-29 160112](https://user-images.githubusercontent.com/91359207/235324548-db087958-2253-4eca-bb0e-841e1504cc44.png)

## Definition
Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed. Meaning, a destructor is the last function that is going to be called before an object is destroyed.
> https://www.geeksforgeeks.org/destructors-c/
<br>


## Encapsulation

>![Encapsulation](https://user-images.githubusercontent.com/91359207/215235674-30039ef6-2fd5-493e-b466-3a02ce413717.png)

## Definition
Encapsulation in C++ is defined as the wrapping up of data and information in a single unit. In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.
> https://www.geeksforgeeks.org/encapsulation-in-cpp/
<br>


## Friends

>![friend](https://user-images.githubusercontent.com/91359207/215235680-0878cdc0-d791-4109-bca7-8b1fb95055cc.png)

## Definition
A friend class can access private and protected members of other classes in which it is declared as a friend. It is sometimes useful to allow a particular class to access private and protected members of other classes. For example, a LinkedList class may be allowed to access private members of Node.
> https://www.geeksforgeeks.org/friend-class-function-cpp/
<br>


## Inheritance

>![inheritance](https://user-images.githubusercontent.com/91359207/215235888-5357e828-935e-46dd-8903-174be4468916.png)

## Definition
The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming. 
Inheritance is a feature or a process in which, new classes are created from the existing classes. The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”. The derived class now is said to be inherited from the base class.
> https://www.geeksforgeeks.org/inheritance-in-c/
<br>


## Instance Variable

>![instance_variable](https://user-images.githubusercontent.com/91359207/215235896-0285d55f-d69a-4935-94ed-0229a53ffd5f.png)

## Definition
Instance variables are declared in a class, but outside a method. When space is allocated for an object in the heap, a slot for each instance variable value is created. Instance variables hold values that must be referenced by more than one method, constructor or block, or essential parts of an object's state that must be present throughout the class.
> https://www.tutorialspoint.com/What-are-class-variables-instance-variables-and-local-variables-in-Java
<br>


## Member/Local Variable

>![instance_variable](https://user-images.githubusercontent.com/91359207/215235929-f40c5ff7-789c-48cb-b4a5-aa0886c314b7.png)

## Definition
Local variables are declared in methods, constructors, or blocks. Local variables are created when the method, constructor or block is entered and the variable will be destroyed once it exits the method, constructor, or block.
> https://www.tutorialspoint.com/What-are-class-variables-instance-variables-and-local-variables-in-Java
<br>


## Method

>![Methods](https://user-images.githubusercontent.com/91359207/215235952-0cf81a1c-48a2-4eb0-aa48-ab620a0bfb68.png)

## Definition
A method is the equivalent of a function in object-oriented programming. A noun is to a verb what a variable is to a method — the methods are the actions that perform operations on a variable. A method accepts parameters as arguments, manipulates these, and then produces an output when the method is called on an object. Methods are similar to functions, but methods are also classified according to their purpose in the class design. In classes, variables are called attributes, so methods often operate on attribute
> https://dev.to/jps27cse/method-and-attribute-in-oop-3kl
<br>


## Multiple Inheritance

>![multiple_inheritance](https://user-images.githubusercontent.com/91359207/215236048-dad2a364-6806-4e8d-8347-c14907607e6a.png)

## Definition
Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.  The constructors of inherited classes are called in the same order in which they are inherited. For example, in the following program, B’s constructor is called before A’s constructor.
<br> A class can be derived from more than one base class.

<br> Eg: 
<br>(i) A CHILD class is derived from FATHER and MOTHER class
<br>(ii) A PETROL class is derived from LIQUID and FUEL class.
> https://www.geeksforgeeks.org/multiple-inheritance-in-c/
<br>


## Object

>![object](https://user-images.githubusercontent.com/91359207/215236026-5b9425f1-31d7-4423-9253-c5bd00d8ee59.png)

## Definition
Objects are key to understanding object-oriented technology. Look around right now and you'll find many examples of real-world objects: your dog, your desk, your television set, your bicycle.
> https://docs.oracle.com/javase/tutorial/java/concepts/object.html
<br>


## Function Overloading

>![overloading](https://user-images.githubusercontent.com/91359207/215236303-9f981d3c-acca-4553-b6a9-838d87f6875e.png)

## Definition
Function overloading is a feature of object-oriented programming where two or more functions can have the same name but different parameters. When a function name is overloaded with different jobs it is called Function Overloading. In Function Overloading “Function” name should be the same and the arguments should be different. Function overloading can be considered as an example of a polymorphism feature in C++.
>https://www.geeksforgeeks.org/function-overloading-c/
<br>


## Operator Overloading

>![Screenshot 2023-04-29 160112](https://user-images.githubusercontent.com/91359207/235324082-76a29ac1-b712-43e1-aef4-08157a81a0a4.png)

## Definition
Operator overloading is a compile-time polymorphism. It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.
In C++, we can make operators work for user-defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +. Other example classes where arithmetic operators may be overloaded are Complex Numbers, Fractional Numbers, Big integers, etc.
> https://www.geeksforgeeks.org/operator-overloading-cpp/
<br>


## Polymorphism

>![polymorphsin](https://user-images.githubusercontent.com/91359207/215236308-55dc0916-b9cd-481b-9f88-18224793c38d.png)

## Definition
The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism is a person who at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee. So the same person exhibits different behavior in different situations. This is called polymorphism. Polymorphism is considered one of the important features of Object-Oriented Programming.
>https://www.geeksforgeeks.org/cpp-polymorphism/
<br>


## Public / Private / Protected

>![access_specifier](https://user-images.githubusercontent.com/91359207/215236216-35469476-de10-4771-a706-943c30726ebc.png)

## Definition

They are access modifiers and help us implement Encapsulation (or information hiding). They tell the compiler which other classes should have access to the field or method being defined.<br>

<br> private - Only the current class will have access to the field or method.

<br> protected - Only the current class and subclasses (and sometimes also same-package classes) of this class will have access to the field or method.

<br> public - Any class can refer to the field or call the method.

<br>This assumes these keywords are used as part of a field or method declaration within a class definition.

> https://stackoverflow.com/questions/1020749/what-are-public-private-and-protected-in-object-oriented-programming
<br>


## Static

>![static](https://user-images.githubusercontent.com/91359207/215236242-7fb59ed9-4935-4425-bb75-79e2e0d067eb.png)

## Definition
Static functions are helpful as they do not rely on an instantiated member of whatever class they are attached to.<br>
Static functions can provide functionality related to an a particular class without requiring the programmer to first create an instance of that class.
>https://stackoverflow.com/questions/35089576/static-methods-in-oop
<br>


## Virtual

>![virtual](https://user-images.githubusercontent.com/91359207/215236337-0a34c6e0-4e26-42bf-8692-abd1c26254dc.png)

## Definition
A virtual function is a member function which is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function. 
>https://www.geeksforgeeks.org/virtual-function-cpp/
