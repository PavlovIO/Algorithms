/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#include "ascii85.h"

int main( int argc, char* argv[])
{
    //Checking for input
    bool decodeMode = false;
    if (argc > 1)
    {
        std::string arg = argv[1];
        if (arg == "-d")
        {
            decodeMode = true;
        } else if (arg == "-e")
        {
            decodeMode = false;
        } else
        {
            std::cerr<<"Usage: "<<argv[0]<<" [-e (encode)] | [-d (decode)]"<<std::endl;
            return 1;
        }
        
    }else
    {
        std::cout<< "No arguments"<<std::endl;
        return 0;
    }
        
    //Encode/decode process     
    if (decodeMode)
    {
        decoder_ascii_85(std::cin, std::cout);
        std::cout<<"\n";
    } else
    {
        encoder_ascii_85(std::cin, std::cout);
        std::cout<<"\n";
    }
    
    return 0;
}
