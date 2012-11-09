#ifndef _SORT_SWAP_H
#define _SORT_SWAP_H 1

#define swap_int(a, b, t) { (t) = (a); (a) = (b); (b) = (t); };

#define swap(a, b, size)						      \
do									      \
{									      \
	register size_t __size = (size);				      \
	register char *__a = (a), *__b = (b);				      \
	do								      \
	{								      \
		char __tmp = *__a;					      \
		*__a++ = *__b;						      \
		*__b++ = __tmp;						      \
	} while (--__size > 0);						      \
} while (0)



#endif