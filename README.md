Numerical Method Library 
============
Develop programs for numerical analysis using iterative methods in C++.  Direct methods can be implemented but GNU/Octave might be the better option that C++.

##Usage
Users will need to define their own system subclass of the available systems classes and define the necessary fields and any inherited pure virtual functions as needed.  Prepared applications might be developed later but until then the user will need to write their own applications with an instance of their defined system object.

This doesn't seem like much but what they will get for free is inherited solution methods which users can access in their applications.  How this will be done hasn't yet been decided.  Currently the plan is to have a null pointer of the appropriate solution subclass as a field of the system class which can be intialized used in the application.

###Example

Example subclass for a simple ideal spring with one end on a wall and another attached to a mass
```
class springTest_system	:public ode, hamiltonian
{
	public:
		void derivative( y_vec& y, y_vec& y_dot );

		const unsigned int varCount = 1;

		double l = 1;	// natural length (delta X_
		double k = 0.1; // spring stiffness
		double m = 1;	// mass of the object
};
```

```
//In main or application

springSystem mySystem;
mySystem.k = 0.2						// change parameters or constants
mySystem.solution = new classicRK();	// choose classical Runge Kutta method
										// could do Euler etc.
mySystem.solution.solve( tFinal, dt );	// ( unsinged int, double )
//mySystem.solution.result				// access the solution, do what you want with it
```

##GOALS
System
It is mandatory that the user extends an existing subclass and use that instead.
User defines needed fields and methods.
Example: Spring
System -> Differential Equation -> { Ordinary, Hamiltonian } -> user extended

Method
Method's available are determined by the class of system used by composition.
Storage
determined by composition of the Method

##Applications

##GUI plotter for solutions
Have an abstract(?) solution Graph class
Add basic graphic classes to it, allow users to extend for more.
Error and Performance Analysis

##Parameter space plotter (Bread and butter)
Output to SQL?
Unix command flags.
Other uses?

##License
GPLv3
