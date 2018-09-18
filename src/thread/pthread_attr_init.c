#include "pthread_impl.h"

extern size_t __default_stacksize;
extern size_t __default_guardsize;

int pthread_attr_init(pthread_attr_t *a)
{
	*a = (pthread_attr_t){0};
	__acquire_ptc();
	a->_a_stacksize = __default_stacksize;
	a->_a_guardsize = __default_guardsize;
	__release_ptc();
	return 0;
}
