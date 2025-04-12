/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#include "ascii85.h"

std::string ascii85(std::string input_str, std::string mode = "-e", bool usefile = false)
{

    // Determine mode and input string
     bool decodeMode = false;

    if (mode == "-d") 
    {
        decodeMode = true;
    } else if (mode == "-e") 
    {
        decodeMode = false;
    } else 
    {
        std::cerr << "Usage: ascii85(<string>, [-e (encode) | -d (decode)])" << std::endl;
        return "";
    }
    
    
    // Determine type of input output
    std::ostringstream output;
    if (usefile) 
    {
        
        std::ifstream input(input_str, std::ios::binary);
        if (!input.is_open())
        {
            std::cerr<<" Couldn't open file "<< input_str <<std::endl;
            return ""; 
        }
        if (decodeMode)
        {
            decoder_ascii_85(input, output);
        } else 
        {
            encoder_ascii_85(input, output);
        }
        input.close();
        
    }else
    {
        std::istringstream input(input_str);
        if (decodeMode)
        {
            decoder_ascii_85(input, output);
        } else 
        {
            encoder_ascii_85(input, output);
        }
    }
        
    // Return the result
    return output.str();
}


