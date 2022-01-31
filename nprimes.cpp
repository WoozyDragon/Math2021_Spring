#define VERSION 0.1.0
#include "nprimes.h"

//returns true if value is prime, false otherwise;
bool isPrime(int value)
{
	/*take the square root, because if we've reached the square root of a number
	* and haven't found any factors, the number is prime.
	*/
	int root{ (int) std::sqrt(value) + 1 };

	//handling edge cases
	if (value == 2) return true;
	else if (value % 2 == 0) return false;
	else if (value <= 1) return false;

	//starting at three, go up until the root or greater.
	//Increment by two because even numbers will already have been removed by one of the edge cases
	for (int i = 3; i <= root; i += 2)
	{
		//if the number is divisible by our counter, then it's not prime
		if (value % i == 0) return false;
	}

	//if we made it up until root with nothing being divisible, then value is prime;
	return true;
}

int getGCD(int a, int b) {
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}

	int r1 = a % b;
	if (r1 == 0) return b;

	while (true) {
		a = b;
		b = r1;
		r1 = a % b;
		if (r1 == 0) return b;
	}
	
}

int argA{};
int argB{};

int g_argA{};
int g_argB{};

int main(int argc, char* argv[])
{
	try //parse command line arguments
	{
		TCLAP::CmdLine cmd(
			"GCD finder", //command description
			' ', //charater between flags and arguments
			version=VERSION //version
		);

		TCLAP::ValueArg<int> argA(
			"a", //short flag
			"argA", //long flag
			"the first number", //description
			true, //required?
			5, //default
			"int (>1)" //human readable description of type
		);
		cmd.add(argA);

		TCLAP::ValueArg<int> argB(
			"b", //short flag
			"argB", //long flag
			"the second number", //description
			true, //required?
			5, //default
			"int (>1)" //human readable description of type
		);
		cmd.add(argB);

		cmd.parse(argc, argv);

		//store parsed command line args in global variables
		g_argA = argA.getValue();
		g_argB = argB.getValue();

	}
	catch (TCLAP::ArgException& e)  // catch exceptions
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}

	// input sanity checks
	if (argA < 1)
	{
		std::cout << "A length greater than 1 is required\n";
		return 1;
	}
	if (argB < 1)
	{
		std::cout << "A count greater than 1 is required\n";
		return 2;
	}
	std::cout << getGCD(argA, argB);
	return 0;
}
