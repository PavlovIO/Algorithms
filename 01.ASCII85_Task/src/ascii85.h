/* Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
*/
#ifndef ASCII85_H
#define ASCII85_H
#include "libraries.h"

int encoder_ascii_85(std::istream &input, std::ostream &output);
int decoder_ascii_85(std::istream &input, std::ostream &output);

#endif
