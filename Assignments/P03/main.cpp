/*********************************************************************
                    
  Author:           Victor Marchesi
  Email:            vzmarchesi1016@my.msutexas.edu
  Label:            05-P03
  Title:            Graphviz Class
  Course:           2143-201
  Semester:         Spring 2023
 
  Description:
        Used 4 different classes to be able to create dot code for
        graphviz. Can create any list you want, but the example code
        in main is singly linked list, doubly linked list, and
        a binary tree. Uses a lot of overloaded functions with classes
        communicating with one another using inheritance.
        
  Usage:
        Test code is provided in main() and should run without any 
        issues
 
  Files: 
        main.cpp    : Main driver file
        output.txt  : Output data that comes from main
        BANNER.cpp  : My banner
*********************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 Class Attribute
 
 Description:
      - creates and modifies attributes using certain methods
        each has their own description
 
 Public Methods:
      - Attribute() {}
      - void addAttribute(string key, string val) { att[key] = val; }
      - void addAttributes(map<string, string> atts)
      - friend ostream &operator<<(ostream &os, Attribute &e)
      - friend ofstream &operator<<(ofstream &os, Edge &e)
 
 Private Methods:
      - 
 
 Usage: 
 
      - 
      
*/
class Attribute
{
protected:
  map<string, string> att; // attributes

public:
//*************************constructors*********************
  /*
    Public : Attribute()
    
    Description:
         - Constructor that creates a default Attribute
    
    Params:
         - No parameters
    
    Returns:
        - returns nothing
   */

  Attribute() {}

//*************************methods************************
  /*
    Public : void addAttribute(string key, string val)
    
    Description:
         - adds attributes based on key and value passed in
    
    Params:
         - string key
         - string val
    
    Returns:
        - returns nothing
  */
  void addAttribute(string key, string val) { att[key] = val; }

  /*
    Public : void addAttributes(map<string, string> atts)
    
    Description:
         - adds attributes based on the values passed in
    
    Params:
         - map<string, string> atts
    
    Returns:
        - returns nothing
  */
  void addAttributes(map<string, string> atts)
  {
    for (auto const &x : atts)
    {
      att[x.first] = x.second;
    }
  }

  /*
    Public : friend ostream &operator<<(ostream &os, Attribute &e)
    
    Description:
         - Overloads ostream operator << and prints out to the console
    
    Params:
         - mstream &os, Edge &e
    
    Returns:
        - returns os by reference so data is printed out to the
          outfile
  */
  friend ostream &operator<<(ostream &os, Attribute &e)
  {
    os << "[";

    int i = 0;
    //for loop to go over the attributes
    for (auto const &x : e.att)
    {
      //printing out to os
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < e.att.size() - 1)
      {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }

  /*
    Public : friend ofstream &operator<<(ofstream &os, Attribute &e)
    
    Description:
         - Overloads ostream operator << and prints out to the console
    
    Params:
         - mstream &os, Edge &e
    
    Returns:
        - returns os by reference so data is printed out to the
          outfile
  */
  friend ofstream &operator<<(ofstream &os, Attribute &e)
  {
    os << "[";

    int i = 0;
    //for loop to go over the attributes
    for (auto const &x : e.att)
    {
      //printing out to os
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < e.att.size() - 1)
      {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }
};

/*
 Class Edge
 
 Description:
      - creates an edge based on parameters passed in
        used to modify or add edges to the graphviz DOT code
 
 Public Methods:
      - Edge()
      - Edge(string color, string arrow)
      - Edge(int start, int end)
      - Edge(map<string, string> atts)
      - friend ostream &operator<<(ostream &os, Edge &e)
      - friend ofstream &operator<<(ofstream &os, Edge &e)
 
 Private Methods:
      - int eid;
      - int start;
      - int end;
 
 Usage: 
      - use is down below above each constructor or method
      
*/
class Edge : public Attribute
{
  int eid;   //edgeid to keep track of edges
  int start; //start of edge
  int end;   // end of edge

public:
//*************************constructors*********************
  /*
    Public : Edge()
    
    Description:
         - Constructor that creates a default Edge
    
    Params:
         - No parameters
    
    Returns:
        - returns nothing
   */
  Edge()
  {
    att["color"] = "black";    // default color
    att["arrow_type"] = "vee"; // default arrow shape
  }

  /*
    Public : Edge(string color, string arrow)
    
    Description:
         - Constructor that creates a an Edge with color and
           arrowstyle input
    
    Params:
         - string color
         - string arrow
    
    Returns:
        - returns nothing
  */
  Edge(string color, string arrow)
  {
    att["color"] = color;      // default color
    att["arrow_type"] = arrow; // default arrow shape
  }

  /*
    Public : Edge(int start, int end)
    
    Description:
         - Constructor that creates an Edge based on
           start end location
    
    Params:
         - int start, int end
    
    Returns:
        - returns nothing
  */
  Edge(int start, int end)
  {
    this->start = start; // start of edge
    this->end = end;    // end of edge
  }

  /*
    Public : Edge(map<string, string> atts)
    
    Description:
         - Constructor that creates an Edge based on the map
           attributes passed in
    
    Params:
         - map<string, string> atts
    
    Returns:
        - returns nothing
  */
  Edge(map<string, string> atts)
  {
    for (auto const &x : atts)// for loop to set the attributes
    {
      att[x.first] = x.second;// setting the attritubes
    }// end of for loop
  }

//*************************methods************************
  /*
    Public : friend ostream &operator<<(ostream &os, Edge &e)
    
    Description:
         - Overloads ostream operator << and prints out to the console
    
    Params:
         - ostream &os
         - Edge &e
    
    Returns:
        - returns os by reference so data is printed out to the
          outfile
  */
  friend ostream &operator<<(ostream &os, Edge &e)
  {
    os << e.start << " -> " << e.end;
    os << " [";

    int i = 0;
    for (auto const &x : e.att)
    {
      os << x.first << "=" << "\"" << x.second << "\"";

      if (i < e.att.size() - 1)
      {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }

  /*
    Public : friend ofstream &operator<<(ofstream &os, Edge &e)
    
    Description:
         - Overloads ofstream operator << and prints out to the
           outfile
    
    Params:
         - fstream &os, Edge &e
    
    Returns:
        - returns os by reference so data is printed out to the
          outfile
  */
  friend ofstream &operator<<(ofstream &os, Edge &e)
  {
    os << e.start << " -> " << e.end;
    os << " [";

    int i = 0;
    for (auto const &x : e.att)
    {
      os << x.first << "=" << "\"" << x.second << "\"";

      if (i < e.att.size() - 1)
      {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }
};

/*
 Class Node
 
 Description:
      -
 
 Public Methods:
      - Node()
      - Node(map<string, string> atts)

 Private Memebers:
      - int nid
 
 Usage: 
      - 
      
*/
class Node : public Attribute
{
  int nid;

public:
  /*
    Public : Node()
    
    Description:
         - Constructor that creates a default Node
    
    Params:
         - No parameters
    
    Returns:
        - returns nothing
   */
  Node()
  {
    att["color"] = "black";  // default color
    att["shape"] = "record"; // default arrow shape
  }

  /*
    Public : Node(map<string, string> atts)
    
    Description:
         - Constructor that creates a Node based
           on the map values passed in
    
    Params:
         - map<string, string> atts
    
    Returns:
        - returns nothing
   */
  Node(map<string, string> atts)
  {
    for (auto const &x : atts)
    {
      att[x.first] = x.second;
    }
  }
};

/*
 Class Graphviz
 
 Description:
      - Creates, modefies and updates nodes and edges based
        on what the user is inputting
 
 Public Methods:
      - GraphViz()
      - GraphViz(string graph_name, string graph_shape)
      - int addNode()
      - int addNode(map<string, string> atts)
      - void updateNode(int id, string key, string value)
      - void updateEdge(int id, string key, string value)
      - void addEdge(int start, int end)
      - void addEdge(int start, int end, map<string, string> att)
      - int addEdge(map<string, string> atts)
      - friend ostream &operator<<(ostream &os, GraphViz &g)
      - friend ofstream &operator<<(ofstream &fout, GraphViz &g)
 
 Private Members:
      - int edgeId;
      - int nodeId;
      - vector<Edge> Edges;
      - vector<Node> Nodes;
      - string graphName;
      - string graphShape;
 
 Usage: 
      - usage is below above each constructor or method 
        definition
      
*/
class GraphViz
{
  int edgeId; //edgeId to keep track of edges
  int nodeId; //nodeId to keep track of edges
  vector<Edge> Edges; //vector of edges
  vector<Node> Nodes; //vector of nodes
  string graphName; // name for graphs
  string graphShape; // name for graph shapes

public:
//*************************constructors*********************
  /*
    Public : GraphViz()
    
    Description:
         - Constructor that creates a Graphviz object
    
    Params:
         - none
    
    Returns:
        - returns nothing
   */
  GraphViz()
  {
    edgeId = 0;
    nodeId = 0;
    graphName = "foo";
  }

  /*
    Public : GraphViz(string graph_name, string graph_shape)
    
    Description:
         - Constructor that creates a Graphviz object based
           graph_name and graph_shape passed in
    
    Params:
         - string graph_name
         - string graph_shape
    
    Returns:
        - returns nothing
   */
  GraphViz(string graph_name, string graph_shape)
  {
    edgeId = 0;
    nodeId = 0;
    graphName = graph_name;
    graphShape = graph_shape;
  }

//*************************methods************************
  /*
    Public : int addNode()
    
    Description:
         - adds a Node based
    
    Params:
         - none
    
    Returns:
        - returns size of the created node node - 1
  */
  int addNode()
  {
    // pushes nodes to the back of vector Node
    Nodes.push_back(Node());
    return Nodes.size() - 1;
  }

  /*
    Public : int addNode(map<string, string> atts)
    
    Description:
         - adds a Node based the map values passed in
    
    Params:
         - map<string, string> atts
    
    Returns:
        - returns size of the created node node - 1
  */
  int addNode(map<string, string> atts)
  {
    Nodes.push_back(Node(atts));

    return Nodes.size() - 1;
  }

  /*
    Public : updateNode(int id, string key, string value)
    
    Description:
         - updates a Node based the id, key and string input
           that is passed in
    
    Params:
         - int id, string key, string value
    
    Returns:
        - nothing
  */
  void updateNode(int id, string key, string value)
  {
    Nodes[id].addAttribute(key, value);
  }

  /*
    Public : updateEdge(int id, string key, string value)
    
    Description:
         - updates a Edge based the id, key and string input
           that is passed in
    
    Params:
         - int id, string key, string value
    
    Returns:
        - nothing
  */
  void updateEdge(int id, string key, string value)
  {
    Edges[id].addAttribute(key, value);
  }

  /*
    Public : void addEdge(int start, int end)
    
    Description:
         - adds an edge based on the values of start and end
    
    Params:
         - int start
         - int end
    
    Returns:
        - nothing
  */
  void addEdge(int start, int end)
  {
    Edges.push_back(Edge(start, end));
  }

  /*
    Public : void addEdge(int start, int end, map<string, string> att)
    
    Description:
         - adds an edge based on the values of start, end, and
           map values passed in
    
    Params:
         - int start
         - int end
         - map<string, string> att
    
    Returns:
        - nothing
  */
  void addEdge(int start, int end, map<string, string> att)
  {
    Edges.push_back(Edge(start, end));
    Edges[Edges.size() - 1].addAttributes(att);
  }

  /*
    Public : void addEdge(map<string, string> att)
    
    Description:
         - adds an edge based on the value of the
           map values passed in
    
    Params:
         - map<string, string> att
    
    Returns:
        - nothing
  */
  int addEdge(map<string, string> atts)
  {
    Nodes.push_back(Node(atts));
    return Nodes.size() - 1;
  }

  /*
    Public : friend ostream &operator<<(ostream &os, Edge &e)
    
    Description:
         - Overloads ostream operator << and prints out to the console
    
    Params:
         - ostream &os
         - Edge &g
    
    Returns:
        - returns os by reference so data is printed out to the
          console
  */
  friend ostream &operator<<(ostream &os, GraphViz &g)
  {
    for (int i = 0; i < g.Nodes.size(); i++)
    {
      os << "\t" << i << " " << g.Nodes[i] << endl;
    }
    for (int i = 0; i < g.Edges.size(); i++)
    {
      os << "\t" << g.Edges[i] << endl;
    }
    return os;
  }

  /*
    Public : friend ofstream &operator<<(ofstream &os, Edge &e)
    
    Description:
         - Overloads ofstream operator << and prints out to the
           outfile
    
    Params:
         - fstream &os, Edge &e
    
    Returns:
        - returns os by reference so data is printed out to the
          outfile
  */
  friend ofstream &operator<<(ofstream &fout, GraphViz &g)
  {
    for (int i = 0; i < g.Nodes.size(); i++)
    {
      fout << "\t" << i << " " << g.Nodes[i] << endl;
    }
    for (int i = 0; i < g.Edges.size(); i++)
    {
      fout << "\t" << g.Edges[i] << endl;
    }
    return fout;
  }
};

int main()
{
  // opening ostream
  ofstream fout;
  fout.open("output.txt");

  // heading
  fout << "Victor Marchesi\n3/9/23\nSpring 23\n\n" << endl;
  
  // create graphviz instances with specific shapes
  GraphViz LL("LinkedList", "LL");
  GraphViz DLL("DoublyLinkedList", "DLL");
  GraphViz BL("BinarySearchTree", "BST");

  // used as an example to load attributes for a node
  map<string, string> norm;
  map<string, string> arrow;
  map<string, string> null;
  
  // attribute that gets a map of attributes and
  // adds them to "A"
  Attribute A;
  norm["shape"] = "record";
  norm["color"] = "blue";
  norm["fillcolor"] = "white";
  A.addAttributes(norm);

  // attribute that gets a map of attributes and
  // adds them to "A"
  null["shape"] = "record";
  null["color"] = "white";
  null["label"] = "NULL";
  A.addAttributes(null);

  // attribute that gets a map of attributes and
  // adds them to "A"
  arrow["color"] = "black";
  arrow["arrowhead"] = "vee";
  A.addAttributes(arrow);

  // start of the singly list graphviz portion
  fout << "Singly linked list\n" << endl;
  fout << "digraph LL {" << endl;
  fout << "\trankdir = LR" << endl;

  // creating linked list and modifying the data using
  // addNode() and updateNode()
  int nodeId = LL.addNode(norm);
  nodeId = LL.addNode(norm);
  LL.updateNode(nodeId, "shape", "circle");
  LL.updateNode(nodeId, "color", "red");
  LL.updateNode(nodeId, "label", "2");
  nodeId = LL.addNode(norm);
  LL.updateNode(nodeId, "shape", "ellipse");
  LL.updateNode(nodeId, "color", "purple");
  LL.updateNode(nodeId, "label", "4");
  nodeId = LL.addNode(norm);
  LL.updateNode(nodeId, "shape", "star");
  LL.updateNode(nodeId, "color", "yellow");
  LL.updateNode(nodeId, "label", "6");
  nodeId = LL.addNode(norm);
  LL.updateNode(nodeId, "shape", "diamond");
  LL.updateNode(nodeId, "color", "green");
  LL.updateNode(nodeId, "label", "8");
  nodeId = LL.addNode(null);

  LL.addEdge(0, 1, arrow);
  LL.addEdge(1, 2, arrow);
  LL.updateEdge(1, "arrowhead", "dot");
  LL.updateEdge(1, "color", "yellow");
  LL.addEdge(2, 3, arrow);
  LL.updateEdge(2, "arrowhead", "odot");
  LL.updateEdge(2, "color", "green");
  LL.addEdge(3, 4, arrow);
  LL.updateEdge(3, "arrowhead", "none");
  LL.updateEdge(3, "color", "pink");
  LL.addEdge(4, 5, arrow);
  LL.updateEdge(4, "arrowhead", "empty");
  LL.updateEdge(4, "color", "green");
  
  fout << LL << "}\n\n" << endl;

 // start of the doubly linked list graphviz portion
  fout << "Doubly linked list\n" << endl;
  fout << "digraph DLL {" << endl;
  fout << "\trankdir = LR" << endl;

  // creating a doubly linked list and modifying the data using
  // addNode() and updateNode()
  nodeId = DLL.addNode(null);
  nodeId = DLL.addNode(norm);
  DLL.updateNode(nodeId, "label", "0");
  DLL.updateNode(nodeId, "shape", "rectangle");
  nodeId = DLL.addNode(norm);
  DLL.updateNode(nodeId, "shape", "circle");
  DLL.updateNode(nodeId, "color", "red");
  DLL.updateNode(nodeId, "label", "2");
  nodeId = DLL.addNode(norm);
  DLL.updateNode(nodeId, "shape", "ellipse");
  DLL.updateNode(nodeId, "color", "purple");
  DLL.updateNode(nodeId, "label", "4");
  nodeId = DLL.addNode(norm);
  DLL.updateNode(nodeId, "shape", "star");
  DLL.updateNode(nodeId, "color", "yellow");
  DLL.updateNode(nodeId, "label", "6");
  nodeId = DLL.addNode(null);

  DLL.addEdge(0, 1, arrow);
  DLL.updateEdge(0, "arrowhead", "none");
  DLL.updateEdge(0, "color", "white");
  DLL.addEdge(1, 0, arrow);
  DLL.addEdge(1, 2, arrow);
  DLL.updateEdge(2, "arrowhead", "odot");
  DLL.updateEdge(2, "color", "green");
  DLL.addEdge(2, 1, arrow);
  DLL.updateEdge(3, "arrowhead", "odot");
  DLL.updateEdge(3, "color", "green");
  DLL.addEdge(2, 3, arrow);
  DLL.updateEdge(4, "arrowhead", "tee");
  DLL.updateEdge(4, "color", "pink");
  DLL.addEdge(3, 2, arrow);
  DLL.addEdge(3, 4, arrow);
  DLL.addEdge(4, 3, arrow);
  DLL.addEdge(4, 5, arrow);

  fout << DLL << "}\n\n" << endl;

  // start of the binary tree list graphviz portion
  fout << "Binary tree\n" << endl;
  fout << "digraph LL {" << endl;
  fout << "\trankdir = TD" << endl;

  // creating a binary tree and modifying the data using
  // addNode() and updateNode()
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "circle");
  BL.updateNode(nodeId, "color", "red");
  BL.updateNode(nodeId, "label", "12");
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "egg");
  BL.updateNode(nodeId, "color", "green");
  BL.updateNode(nodeId, "label", "6");
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "egg");
  BL.updateNode(nodeId, "color", "blue");
  BL.updateNode(nodeId, "label", "6");
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "record");
  BL.updateNode(nodeId, "color", "yellow");
  BL.updateNode(nodeId, "label", "2");
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "record");
  BL.updateNode(nodeId, "color", "yellow");
  BL.updateNode(nodeId, "label", "3");
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "doublecircle");
  BL.updateNode(nodeId, "color", "pink");
  BL.updateNode(nodeId, "label", "2");
  nodeId = BL.addNode(norm);
  BL.updateNode(nodeId, "shape", "doublecircle");
  BL.updateNode(nodeId, "color", "pink");
  BL.updateNode(nodeId, "label", "3");

  BL.addEdge(0, 1, arrow);
  BL.updateEdge(0, "arrowhead", "odot");
  BL.updateEdge(0, "color", "blue");
  BL.addEdge(0, 2, arrow);
  BL.updateEdge(1, "color", "green");
  BL.addEdge(1, 3, arrow);
  BL.updateEdge(2, "arrowhead", "none");
  BL.updateEdge(2, "color", "pink");
  BL.addEdge(1, 4, arrow);
  BL.updateEdge(3, "arrowhead", "none");
  BL.updateEdge(3, "color", "pink");
  BL.addEdge(2, 5, arrow);
  BL.updateEdge(4, "arrowhead", "empty");
  BL.updateEdge(4, "color", "red");
  BL.addEdge(2, 6, arrow);
  BL.updateEdge(5, "arrowhead", "empty");
  BL.updateEdge(5, "color", "red");

  fout << BL << "}" << endl;

  //closing the outfile
  fout.close();
  return 0;
}