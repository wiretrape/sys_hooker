#include <linux/syscalls.h>
#include "types.h"

asmlinkage long (*original_mkdir)(const char __user *pathname, umode_t mode);

asmlinkage long mkdir_hook(const char __user *pathname, umode_t mode)
{
    printk(KERN_INFO "mkdir_hook: Intercepted mkdir system call\n");
    return original_mkdir(pathname, mode);
}
