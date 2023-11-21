#include "thread.h"
#include <stdlib.h>

void init_thread(thread_t *thread)
{
  thread->left = NULL;
  thread->right = NULL;
}

void thread_add_next(thread_t *curr_thread, thread_t *new_thread)
{
  if(!curr_thread->right)
  {
      curr_thread->right = new_thread;
      curr_thread->left = new_thread;
      new_thread->left = curr_thread;
      new_thread->right = curr_thread;
      return;
  }

  new_thread->left = curr_thread;

  new_thread->right = curr_thread->right;

  new_thread->right->left = new_thread;

  curr_thread->right = new_thread;
}

void thread_add_before(thread_t *curr_thread, thread_t *new_thread)
{
  if(!curr_thread->right)
  {
      curr_thread->right = new_thread;
      curr_thread->left = new_thread;
      new_thread->left = curr_thread;
      new_thread->right = curr_thread;
      return;
  }

  new_thread->right = curr_thread;

  new_thread->left = curr_thread->left;

  new_thread->left->right = new_thread;

  curr_thread->left = new_thread;
}
