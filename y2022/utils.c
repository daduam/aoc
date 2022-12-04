#include "stdio.h"
#include "stdlib.h"

/**
 * stream_file_to_stdin - Open the input file for streaming in stdin
 *
 * @filename: Input file path.
 */
void stream_file_to_stdin(char *filename)
{
	if (freopen(filename, "r", stdin) == NULL)
	{
		perror("freopen() failed.");
		exit(1);
	}
}
