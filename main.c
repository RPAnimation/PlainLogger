#include "logger.h"
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main(int argc, char const *argv[])
{
	int sample_buffer[BUFFER_SIZE] = { 0 };

	if (logger_start("log.txt", sample_buffer, sizeof(int) * BUFFER_SIZE) != 0)
	{
		printf("Couldn't start logger!\n");
		return 1;
	}
	logger_set_level(LOG_MAX);

	logger_dump();

	logger_log("Allocated: %d bytes of memory!", 128);

	logger_stop();
	return 0;
}