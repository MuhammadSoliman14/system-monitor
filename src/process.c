#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


#define INITIAL_CAPACITY 100
#define GROWTH_FACTOR 2

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


// create and initialize a new ProcessList
ProcessList* create_process_list(){
    ProcessList *list = malloc(sizeof(ProcessList));
    if (!list) return NULL;

    list-> processes = malloc(sizeof(Process) * INITIAL_CAPACITY);
    if (!list-> processes){
        free(list);
        return NULL;
    }

    list -> count = 0;
    list -> capacity = INITIAL_CAPACITY;

    return list;

}


void free_process_list(ProcessList *list){     // ffunction takes a list pointer (that points to a processList)
    if (list){                          // check if pointer is valid
        if (list -> processes){         // check if processes array exists
            free (list-> processes);     //free the array
        }
        free (list);                       // free the pointer
    }
}


void add_process (ProcessList *list, Process Proc){
    if (!list) return;

    //resize if needed 
    if (list -> count >= list->capacity){
        int new_capacity = list -> capacity * GROWTH_FACTOR;
        Process *new_processes = realloc(list -> processes, sizeof(Process) * new_capacity);
        
        if (!new_processes){
            fprintf(stderr, "failed to resize process list");
            return;
        }
        
        list->processes = new_processes;
        list->capacity = new_capacity;
    }

    }


    void clear_process_list(ProcessList *list){
        if (list){
        list -> count =0;
        }
    }