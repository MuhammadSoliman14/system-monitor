#include <sys/types.h>

typedef struct process
{
    pid_t pid;
    pid_t ppid;
    char name[256];
    char state;     // R,S,D,Z
    unsigned long vsize;    // virtual memory size in bytes
    unsigned long rss ;      // resident set size in bytes
} Process;


typedef struct process_list
{
    Process *processes;
    size_t count;
    size_t capacity;
} ProcessList;

