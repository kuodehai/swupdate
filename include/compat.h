/*
 * Author: Christian Storm
 * Copyright (C) 2018, Siemens AG
 *
 * SPDX-License-Identifier:     GPL-2.0-or-later
 */

#pragma once

#ifndef strndupa
/*
 * Define char *strndupa(const char *s, size_t n)
 * for, e.g., musl (https://www.musl-libc.org/)
 * which does not bother to implement this function.
 */
#define strndupa(s, n)                          \
	(__extension__({                            \
		const char *__in = (s);                 \
		size_t __len = strnlen(__in, (n)) + 1;  \
		char *__out = (char *)alloca(__len);    \
		__out[__len - 1] = '\0';                \
		(char *)memcpy(__out, __in, __len - 1); \
	}))
#endif