#include <purescript.h>
#include "Effect.h"

PURS_FFI_FUNC_3(Test_Assert_assert$, msg, cond, _, {
	purs_assert(purs_any_get_int(cond), "%s", purs_any_get_string(msg));
	return NULL;
});

PURS_FFI_FUNC_2(Test_Assert_checkThrows, f, _, {
	const purs_any_t * r = purs_any_app(f, NULL);
	return purs_any_bool(Effect_is_error(r));
});
