#ifndef __THREAD__
#define __THREAD__

typedef struct _thread
{
    struct _thread * left;
    struct _thread * right;
} thread_t;

void
init_thread(thread_t *thread);

void
thread_add_next(thread_t *curr_thread, thread_t *new_thread);

void
thread_add_before(thread_t *curr_thread, thread_t *new_thread);

static inline thread_t *
get_base(thread_t * base)
{
	return base->right;
};

#define THREAD_TO_STRUCT(fn_name, struct_name, struct_field)\
static inline struct_name * fn_name(thread_t *ptr)			\
{return (struct_name *)((char *)(ptr) - (char *)&(((struct_name *)0)->struct_field));}

#endif
