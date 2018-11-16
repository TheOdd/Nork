#include "StatusCodes.h"

using namespace StatusCode;

unsigned int Code::globalCounter = 0;

const Code InputStatus::SUCCESS = Code();
const Code InputStatus::SUCCESS::SUCCESS_QUIT = Code();

const Code InputStatus::ERR = Code();
const Code InputStatus::INPUT_ERR::INVALID_KEYWORD = Code();
const Code InputStatus::INPUT_ERR::INVALID_PARAM = Code();
const Code InputStatus::INPUT_ERR::MISSING_PARAM = Code();
const Code InputStatus::INPUT_ERR::EXTRA_PARAM = Code();
