#include "runtime/purescript.h"
#include "Effect.h"

EFFECT_FUNC_2(Test_Assert_assert$, msg, cond, {
	if (*purs_any_get_int(cond) != 1) {
		return Effect_error(msg);
	}
	return (const purs_any_t *) NULL;
})

EFFECT_FUNC_1(Test_Assert_checkThrows, f, {
	const purs_any_t * r = purs_any_app(f, NULL);
	return Effect_is_error(r);
})
