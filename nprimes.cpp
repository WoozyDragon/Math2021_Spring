#define VERSION "2.0.0"

#include "nprimes.h"

// command line arguments stored as global variables
int g_totalString{};
int g_numberOfString{};
bool g_noAutoReturn{};

//returns true if value is prime, false otherwise;
bool isPrime(int value)
{
	/*take the square root, becuase if we've reached the square root of a number
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

int main(int argc, char *argv[])
{
	try //parse command line arguments
	{
		TCLAP::CmdLine cmd(
			"Consecutive Non-Prime Finder", //command description
			' ', //charater between flags and arguments
			VERSION //version
		);

		TCLAP::ValueArg<int> lenArg(
			"l", //short flag
			"length", //long flag
			"how many consecutive non-primes to generate per set", //description
			true, //required?
			5, //default
			"int (>1)" //human readable description of type
		);
		cmd.add(lenArg);

		TCLAP::ValueArg<int> numArg(
			"c", //short flag
			"count", //long flag
			"how many sets to generate", //description
			false, //required?
			1, //default
			"int (>0)" //human readable description of type
		);
		cmd.add(numArg);

		TCLAP::SwitchArg waitArg(
			"w", //short flag
			"wait", //long flag
			"waits for the user to hit return before returning", //description
			false //default
		);
		cmd.add(waitArg);

		cmd.parse( argc, argv );

		//store parsed command line args in global variables
		g_totalString = lenArg.getValue();
		g_numberOfString = numArg.getValue();
		g_noAutoReturn = waitArg.getValue();

	} catch (TCLAP::ArgException &e)  // catch exceptions
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }

	// input sanity checks
	if (g_totalString <= 1)
	{
		std::cout << "A length greater than 1 is required\n";
		return 1;
	}
	if (g_numberOfString <= 0)
	{
		std::cout << "A count greater than 0 is required\n";
		return 2;
	}

	//**INTERNAL VARIABLES. DO NOT TOUCH**
	//our counter, for how many primes in a row we have
	int counter{ 0 };
	//a storage box for our final string(s)
	std::vector <int> finalNumber;

	//start our counter at two and try every number
	//goes on forever (while(true) loop with a bit of extra stuff)
	for (int i = 2; true; ++i)
	{
		//if the number is prime
		if (isPrime(i))
		{
			//counter gets reset
			counter = 0;
		//number is not prime
		} else {
			//increase counter
			++counter;
		}

		//if the counter is the same length as our specified string length
		//then we can add the result to our list
		if (counter == g_totalString) {
			finalNumber.push_back(i);

			//reset the counter
			counter = 0;

			//if we have g_numberOfString numbers, then we're good and can exit
			if (finalNumber.size() >= g_numberOfString)
			{
				break;
			}
		}
	}

	//prints out our results
	//the big loop goes through every item stored in the array, which is every string of non-primes
	//the inside loop starts i at our string length, and decreases it from there
	//this allows it to print out the numbers in order.
	//the weirdness with one thing being outside the loop is to get rid of the ending comma
	for (int j = 0; j < g_numberOfString; ++j)
	{
		for (int i = g_totalString - 1; i >= 1; --i)
		{
			std::cout << finalNumber[j] - i << ", ";
		}
		std::cout << finalNumber[j] << '\n';
	}

	//if the wait flag was used stop the program from terminating,
	//mostly for windows to make sure the window doesn't close by itself;
	if (g_noAutoReturn)
	{
		std::cin.get();
	}

	//program executed successfully.
	return 0;
}
