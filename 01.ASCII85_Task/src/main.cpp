/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#include "ascii85.h"

int main( int argc, char* argv[])
{
    //Checking for input
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [-e (encode) | -d (decode)] <string>" << std::endl;
        return 1;
    }
    
    // Determine mode and input string
    std::string mode = argv[1];
    std::string input_str = argv[2];
    bool decodeMode = false;

    if (mode == "-d") {
        decodeMode = true;
    } else if (mode == "-e") {
        decodeMode = false;
    } else {
        std::cerr << "Usage: " << argv[0] << " [-e (encode) | -d (decode)] <string>" << std::endl;
        return 1;
    }
    
    // Use stringstream for input and output
    std::stringstream input(input_str);
    std::stringstream output;


    // Encode or decode based on mode
    if (decodeMode) {
        if (decoder_ascii_85(input, output) != 0) {
            return 1;
        }
    } else {
        if (encoder_ascii_85(input, output) != 0) {
            return 1;
        }
    }
    
    // Print the result
    std::cout << output.str() << std::endl;
    
    return 0;
}
