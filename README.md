Numerical Non-Linear Computation Library
============
_This project is currently dead as I want to merge with, or at least use containers from, far more established projects_

This library aims to provide simple templates for creating programs to solve numerical systems.  Currently, only methods used to solve differential equations are being implemented.  But once things get working other problems will be added.
##Usage
Users will need to define their own system subclass of the available systems classes and define the necessary fields and any inherited pure virtual functions as needed.  Prepared applications might be developed later but until then the user will need to write their own applications with an instance of their defined system object.

This doesn't seem like much but what they will get for free is inherited solution methods which users can access in their applications.  How this will be done hasn't yet been decided.  Currently the plan is to have a null pointer of the appropriate solution subclass as a field of the system class which can be intialized used in the application. 

###Example
Example system for an ideal spring connecting two equal, gravitationally attracted masses.
__LATER__ see `demo/springTest.cpp` for working version of implementation.
<!--```CPP
    class springTest_system	:public ode, hamiltonian
    {
    	public:
    		void derivative( y_vec& y, y_vec& y_dot );		//inherited by ODE needed for the solution
    		const unsigned int varCount = 1;
    		double l = 1;	// natural length (delta X)
    		double k = 0.1; // spring stiffness
    		double m = 1;	// mass of the object
    };
```
In main or application
```CPP
springSystem mySystem;
mySystem.k = 0.2						// change parameters or constants
mySystem.solution = new classicRK();	// choose classical Runge Kutta method
										// could do Euler etc.
mySystem.solution.solve( tFinal, dt );	// ( unsinged int, double )
//mySystem.solution.result				// access the solution, do what you want with it
```
-->
##License
This project is licensed using the Apache v2.0 license.  Most files are marked accordingly with the Apache license.  Any file not marked with the Apache license still carries the same license.
##GOALS
####Good lord
Why is `y_vec` an `std::vector` and not an `std::array`?  Get on that...

###Storage
- Rename this `Containters`
- New:
  * `twoDVec` -> (interface) `selective` -> `sheetYSub`
  * (interfaces) {`packable`, `printable`} -> `sheetYSub` (yes multiple inheritance)
- Change `printable` to `streamable`
  * `streamable` Containers return a null terminated character stream of elements in whatever order they want.
    + _eg_ `sheetYSub` would stream differently than `sheetElSub`.
  * `IO` class receives the stream and does what it wants with it.
    + print to file (actual or std{out,err,log}.
    + re create `IO` class.
- Implement single vector storage so if we ever use only one varible we don't have one element subvectors
- Make sheetElSub.

###Methods 
- Decide heirarchy for Ordered and Partial Differential Equations. (ODEs, and PDEs)
  * ODE vs PDE 
    + Difference is in dFunc_t which is determined by the system. Implementation wise, methods are ignorant of whether the system is an ODE or PDE as that is done in the `derivative` function.
  * Explicit vs Implicit
    + Need to pass error or tolerance arguments
      - special needs for hamiltonian systems
- Use variants of Euler's method for testing.
- Use BOOST FOREACH with zip iterators

###Systems
- Finish Methods
- Get that demo up DONE

##Optimizations

##Possible Applications

###GUI plotter for solutions
- Have an abstract solution Graph class
- Add basic graphic classes to it, allow users to extend for more.
- Error and Performance Analysis

###Parameter space plotter
- First complicated application
- Compare with senior thesis for performance

