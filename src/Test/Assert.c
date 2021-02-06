#include <purescript.h>

PURS_FFI_FUNC_3(Test_Assert_assert$, msg, cond, _) {
	const purs_str_t *str = purs_any_get_string(msg);
	purs_assert(purs_any_get_int(cond), "%s", str->data);
	return purs_any_null;
}

// There's no concept of "throwing exceptions" in C.
// We still evaluate the fn.
PURS_FFI_FUNC_2(Test_Assert_checkThrows, f, _) {
	const purs_any_t r = purs_any_app(f, purs_any_null);
	return purs_any_false;
}
