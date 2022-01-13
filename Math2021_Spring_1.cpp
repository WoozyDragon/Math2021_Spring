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
	//change this to find a longer or shorter stirng
	int totalString{ 10 };

	//**INTERNAL VARIABLES. DO NOT TOUCH**
	//our counter, for how many primes in a row we have
	int counter{ 0 };
	//a storage box for our final string
	int finalNumber{ 0 };

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
		//then we can exit the loop, being sure to save the number. 
		if (counter == totalString) {
			finalNumber = i;
			break;
		}
	}

	//prints out our results
	//starts i at our string length, and decreases it from there
	//this allows it to print out the numbers in order.
	for (int i = totalString - 1; i >= 0; --i)
	{
		std::cout << finalNumber - i << ", ";
	}

#ifdef __linux__
	std::string test{};
	std::cin >> test;
#endif
	return 0;
}
