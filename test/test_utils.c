#include <fcntl.h>
#include <unistd.h>

#include "test_utils.h"

void fill_with_random(void *ptr, int nbytes)
{
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, ptr, nbytes);
    close(fd);
}

