/***
 * Visibility vs Accessibility
 * 
 */



class Widget
{
public:
  void doSomething( int );  // (1)
private: //private not visibility label, its access label
  void doSomething( double ); // (2)
};

Widget w{};
w.doSomething( 1.0 );   //trying to set double, will return an error, excess violation

//consider classes as a class objects,
//by default everything is visible
//same functiom called inside and outside of the class

//the order:
// 1- name lookup, all visable
// 2- overload resuolution
// 3- access labels, like in this example of private
// 4- =delete check if the best match is deleted