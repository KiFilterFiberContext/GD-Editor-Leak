#pragma once

#include <jni.h>
#include <errno.h>

#include <string.h>

#include <unistd.h>
#include <sys/resource.h>

#include <syscall.h>
#include <sys/wait.h>

#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <elf.h>
#include <ucontext.h>
#include <asm/sigcontext.h>

#include <sys/types.h>
#include <sys/user.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/uio.h>

#include <android/log.h>
#include <linux/elf.h>

#include <dlfcn.h>

#include <malloc.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "engine/inlineHook.h"

#include "engine/mem.h"
#include "engine/utils.h"
#include "engine/softbp.h"