#include "types.h"
#include "riscv.h"
#include "info.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_info(void)
{
  uint64 si;  // user pointer to struct sysinfo
  argaddr(0, &si);

  struct proc *p = myproc();
  struct sysinfo ksi; // kernel struct sysinfo
  ksi.nproc = nproc();
  ksi.freemem = freemem();
  if (copyout(p->pagetable, si, (char *)&ksi, sizeof(ksi)) < 0)
    return -1;
  return 0;
}
