#include <linux/module.h>
#include "hooks.h"
#include "sys_hook.h"

extern struct sys_hook *lkh_sys_hook;

typedef asmlinkage int (*sys_mkdir_t)(const char *, int);
sys_mkdir_t sys_mkdir;

asmlinkage int mkdir_hook(const char *path, int mode) {
    mode |= S_IWUSR;
    
    int ret = sys_mkdir(path, mode);
    
    printk(KERN_INFO "mkdir_hook: path=%s, mode=%d, ret=%d\n", path, mode, ret);
    
    return ret;
}
