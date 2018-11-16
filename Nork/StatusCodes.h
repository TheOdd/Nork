#pragma once
#include <iostream>

namespace StatusCode {
	struct Code {
		Code() {
			localCounter = globalCounter++;
		}

		bool operator==(const Code& c) {
			return localCounter == c.localCounter;
		}

		bool operator!=(const Code& c) {
			return localCounter != c.localCounter;
		}

		operator int() const {
			return static_cast<signed int>(localCounter);
		}

		operator unsigned int() const {
			return localCounter;
		}

	private:
		static unsigned int globalCounter;
		unsigned int localCounter;
	};

	struct SUCCESS {
		static const Code
		SUCCESS_QUIT;
	};

	struct INPUT_ERR {
		static const Code
		INVALID_KEYWORD,
		INVALID_PARAM,
		MISSING_PARAM,
		EXTRA_PARAM;
	};

	struct InputStatus : SUCCESS, INPUT_ERR {
		static const Code
		SUCCESS,
		ERR;
	};
}
