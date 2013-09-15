Numerical Method Library 
============
Develop programs for numerical analysis using iterative methods in C++.  Direct methods can be implemented but GNU/Octave might be the better option than C++.

##Usage
Users will need to define their own system subclass of the available systems classes and define the necessary fields and any inherited pure virtual functions as needed.  Prepared applications might be developed later but until then the user will need to write their own applications with an instance of their defined system object.

This doesn't seem like much but what they will get for free is inherited solution methods which users can access in their applications.  How this will be done hasn't yet been decided.  Currently the plan is to have a null pointer of the appropriate solution subclass as a field of the system class which can be intialized used in the application.

###Example
Example subclass for a simple ideal spring with one end on a wall and another attached to a mass
```CPP
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

##GOALS

###Storage
- Finish the packable twoDVec subclasses 
- make packable single vector storage
	* make packable parent class that both twoDvec and above class inherits?
- Recreate above classes using arrays instead of `std::vector`
	* Test if there is a difference

###Methods 
Finish Storage

###Systems
Finish Methods

##Possible Applications

###GUI plotter for solutions
- Have an abstract solution Graph class
- Add basic graphic classes to it, allow users to extend for more.
- Error and Performance Analysis

###Parameter space plotter
First complicated application
Compare with senior thesis for performance

##License
Apache v2.0
