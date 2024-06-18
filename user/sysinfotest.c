#include "kernel/types.h"
#include "kernel/info.h"
#include "user.h"

struct sysinfo;

int
main(int argc, char *argv[])
{
  struct sysinfo si;
  info(&si);
  printf("nproc: %d\nfreemem: %d bytes\n", si.nproc, si.freemem);

  exit(0);
}