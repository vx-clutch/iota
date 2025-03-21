#include <stdlib.h>
#include "syslog/error.h"

int
main(void)
{
  pwarning("iota is in its *alpha* stages of development expect missing features or other errors. Please report any bugs to the developers.");
  return EXIT_SUCCESS;
}
