/**
 * @file exceptions.cpp
 * @brief Definitions of the Exception class for error handling.
 * 
 * This source file defines the Exception functions and implementations.
 * 
 * @copyright 2025 MTA
 * @author 
 * Ing. Jiri Konecny
 */

 #include "exceptions.hpp"

Exception::Exception(std::exception ex)
{
    Code = ErrorCode::NOT_DEFINED_ERROR;
    Message = ex.what();
    Source = "std::exception";
    innerException = nullptr;
}

Exception::Exception(Exception* inner)
{
    Code = ErrorCode::NOT_DEFINED_ERROR;
    Message = "Unknown error";
    Source = "Unknown source";
    innerException = inner;
}

Exception::Exception(const std::string &source, Exception* inner)
{
    Code = ErrorCode::NOT_DEFINED_ERROR;
    Message = "Unknown error";
    Source = source;
    innerException = inner;
}

Exception::Exception(const std::string &message, ErrorCode code)
{
    Code = code;
    Message = message;
    Source = "Unknown source";
    innerException = nullptr;
}

Exception::Exception(const std::string &source, const std::string &message, ErrorCode code, Exception* inner)
    : Code(code), Message(message), Source(source), innerException(inner) {}

Exception::~Exception() { delete innerException; }

std::string Exception::flush(int level) const {
    std::string message = "";
    for (int i = 0; i < level; i++) {
        message += buildMessage(" \t");
    }
    message += buildMessage("(%s) Exception catch: %s\n", Source.c_str(), Message.c_str());
    if (innerException) {
        message += innerException->flush(level + 1);
    }
    return message;
}

void Exception::print() const {
    std::string message = flush(0);
    if (Code == ErrorCode::CRITICAL_ERROR_CODE) {
        // For critical errors, splash the message as well
        splashMessage("%s", message.c_str());
    }
    logMessage("%s", message.c_str());
}