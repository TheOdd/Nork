#pragma once

namespace StatusCode {
	enum class InputStatus {
		SUCCESS,
		SUCCESS_QUIT,
		ERR_INVALID_KEYWORD,
		ERR_INVALID_PARAM,
		ERR_MISSING_PARAM,
		ERR_EXTRA_PARAM,
	};
}
