#include <purescript.h>
#include "Effect.h"

EFFECT_FUNC_2(Test_Assert_assert$, msg, cond) {
	const purs_str_t* s = purs_any_force_string(msg);
	purs_assert(purs_any_force_int(cond) == 1, "%s", s->data);
	PURS_RC_RELEASE(s);
	return purs_any_null;
}

EFFECT_FUNC_1(Test_Assert_checkThrows, f) {
	return purs_any_false; /* "throwing" exceptions is not a thing in C */
}
