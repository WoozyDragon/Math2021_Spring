#define VERSION "2.0.0"

#include "Math2021_Spring_1.h"


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

int main()
{
	//the length of the string of numbers we want. 
	//asks for user input at the start of each run
	int totalString{ 0 };

	std::cout << "Please enter the length of the string on non-primes: ";
	std::cin >> totalString;
	if (totalString <= 1)
	{
		std::cout << "Please enter a number greater than 1";
		return 1;
	}

	//the number of strings to find.
	//asks for user input at the start of each run
	int numberOfString{ 0 };
	std::cout << "Please enter the number of strings to find: ";
	std::cin >> numberOfString;
	if (numberOfString <= 0)
	{
		std::cout << "Please enter a number greater than 0";
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
		if (counter == totalString) {
			finalNumber.push_back(i);
			
			//reset the counter
			counter = 0;
			
			//if we have numberOfString numbers, then we're good and can exit
			if (finalNumber.size() >= numberOfString)
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
	for (int j = 0; j < numberOfString; ++j)
	{
		for (int i = totalString - 1; i >= 1; --i)
		{
			std::cout << finalNumber[j] - i << ", ";
		}
		std::cout << finalNumber[j] << '\n';

	}
	

	//make sure the window doesn't close by itself;
	std::string test{};
	std::cin >> test;

	//program executed successfully. 
	return 0;
}
