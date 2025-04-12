/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#include "ascii85.h"

int main( int argc, char* argv[])
{
    //Checking for input
    if (argc != 4)
    {
        std::cerr << "Usage: ./output [-e|-d] <string_or_file> <bool>(usefile)";
        return 1;
    }
    std::string mode = argv[1];
    std::string input_str = argv[2];
    std::string usefile_str = argv[3];
    bool usefile = (usefile_str == "1" || usefile_str == "true");

    std::string result = ascii85(input_str,mode,usefile);
    std::cout << result << std::endl;
}
