/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#include "ascii85.h"

int decoder_ascii_85(std::istream &input, std::ostream &output) {
    const uint32_t powers[] = {85*85*85*85, 85*85*85, 85*85, 85, 1};  // Старшие разряды сначала!
    std::vector<unsigned char> buffer;
    std::vector<char> outputData;
    char ch;

    while (input.get(ch)) {
        if (ch == '~') {
            if (input.peek() == '>') {
                input.get(ch);  // Пропускаем '>'
                break;
            } else {
                std::cerr << "Invalid ASCII85 termination\n";
                return 1;
            }
        }

        if (ch >= '!' && ch <= 'u') {
            buffer.push_back(ch);
        } else if (ch != ' ' && ch != '\n' && ch != '\r' && ch != '\t') {
            std::cerr << "Invalid ASCII85 character: '" << ch << "'\n";
            return 1;
        }

        if (buffer.size() == 5) {
            uint32_t num = 0;
            for (int i = 0; i < 5; ++i) {
                num += (buffer[i] - 33) * powers[i];
            }

            for (int i = 3; i >= 0; --i) {
                outputData.push_back((num >> (8 * i)) & 0xFF);
            }
            buffer.clear();
        }
    }

    // Обработка остатка (паддинг)
    if (!buffer.empty()) {
        uint32_t num = 0;
        int s = buffer.size();

        for (int i = 0; i < s; ++i) {
            num += (buffer[i] - 33) * powers[i];
        }

        int bytes_to_output = s - 1;
        for (int i = 0; i < bytes_to_output; ++i) {
            outputData.push_back((num >> (8 * (3 - i))) & 0xFF);
        }
    }

    output.write(outputData.data(), outputData.size());
    return 0;
}



