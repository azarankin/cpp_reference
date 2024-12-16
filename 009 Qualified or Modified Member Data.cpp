/***
 * Qualified or Modified Member Data
 * Trouble with const data members or reference member
 * Don't make data members const or reference
 * That will not be included inside the assignment operator (copy assignment and move assignment)
 */


struct  Widget
{
  int const i;
  double& d;
  //This operations will not automaticly generate
  Widget& operator=( Widget const& ); // immidiatly deleted
  Widget& operator=( Widget&&  ); // not declared
  //Because it not clear what do you want
};



//Reccomend not to have const data members
//Data members should be private
//Not applied to static const, its not part of Widget itself

//reference store as a pointer, and receive the reference
struct Widget2
{
public:
  Widget2( double& d ) : pd_(&d) {}
 
  double& get() noexcept { return *pd_; }
  double const& get() const noexcept { return *pd_; }

private:
  double* pd_;
};


//use reference wrapper
//better alternative
#include <functional>
struct Widget3
{
public:
  Widget3( double& d ) : pd_(d) {}

  double& get() noexcept { return pd_; }
  double const& get() const noexcept { return pd_; }

private:
  std::reference_wrapper<double> pd_;
};

