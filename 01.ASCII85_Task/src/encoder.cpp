/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#include "ascii85.h"

int encoder_ascii_85(std::istream &input, std::ostream &output)
{
    const uint32_t powers[] = {1, 85, 85*85, 85*85*85, 85*85*85*85};
    std::vector<char> outputData;
    std::vector<unsigned char> buffer;
    char ch;
    
    while (input.get(ch))
    {
        buffer.push_back(static_cast<unsigned char>(ch));
        if (buffer.size() == 4 )
        {
            uint32_t num;
            num = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
            for (int i = 4; i>=0; --i)
            {
                outputData.push_back(static_cast<char>(num / powers[i] + 33));
                num %= powers[i];
            }
            buffer.clear();
        } 
    }
    if (!buffer.empty())
    {
        int s = buffer.size();
        for (int i=0; i + s < 4; ++i)
        {
            buffer.push_back(static_cast<unsigned char>(0));
        }
        uint32_t num;
        num = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
        for (int i = 4; i>=4-s; --i)
        {
            outputData.push_back(static_cast<char>(num / powers[i] + 33));
            num %= powers[i];
        }
    }
    output.write(outputData.data(), outputData.size());
    output << "~>";  
    return 0;  
}
