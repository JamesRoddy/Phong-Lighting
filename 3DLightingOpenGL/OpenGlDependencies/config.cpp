#include "config.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::vector<std::string> splitline(std::string line, std::string seperator) {

	std::vector<std::string> splitlines;
	size_t position = 0; // the size_t vairbale is used to store the size of an array in bytes and in this case is used to store the index postion of each instance of the serpertor character found in the file 
	std::string token; // this will be what is in beteween the seprrators wihtin the file 

	while (position = line.find(seperator) != std::string::npos) { // npos dictates the end of the string as a constant value meaning that if our seperator cant be found in the line string in the  next instance of the while loop then we have reached the end of the line  

		token = line.substr(0, position);// this will slice the string starting from index postion 0 up to the seperator giviing us the string in between the seperators 
		splitlines.push_back(token);
		// the subsrt mehtod will take a starting position and then create a string from that postion of a specifced length in the second parameter 
		line.erase(0, position + seperator.size()); //  ensures that both the seperator and the current token we are targetting are removed from the line for the next ittertaion
		// we are essentially erasing from index 0 up to the index postion of the sperator value as the sperator will have a length of 1 
		splitlines.push_back(line); // takes into account the last word on the line as it wont have a seperator  after it 
	}
	return splitlines;

}