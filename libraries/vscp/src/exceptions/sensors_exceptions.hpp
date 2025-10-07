
/**
 * @file sensors_exceptions.hpp
 * @brief Specialized exceptions for sensor operations.
 *
 * This header defines exception classes for various sensor-related errors, such as initialization,
 * synchronization, reset, connection, and disconnection failures. These exceptions inherit from the base
 * Exception class and provide constructors for different error reporting scenarios.
 *
 * @copyright 2025 MTA
 * @author Ing. Jiri Konecny
 */

#ifndef SENSORS_EXCEPTIONS_HPP
#define SENSORS_EXCEPTIONS_HPP

#include "exceptions.hpp"


/**
 * @class SensorInitializationFailException
 * @brief Exception for sensor initialization failures.
 *
 * Use this exception to indicate errors during sensor initialization.
 */
class SensorInitializationFailException : public Exception
{
public:
    SensorInitializationFailException(const std::string &source, Exception* innerException) : Exception(source, innerException) {}
    SensorInitializationFailException(const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(message, code) {}
    SensorInitializationFailException(const std::string &source, const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code) {}
    SensorInitializationFailException(const std::string &source, const std::string &message, Exception *innerException, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code, innerException) {}
    ~SensorInitializationFailException(){}
};


/**
 * @class SensorSynchronizationFailException
 * @brief Exception for sensor synchronization failures.
 *
 * Use this exception to indicate errors during sensor synchronization.
 */
class SensorSynchronizationFailException : public Exception
{
public:
    SensorSynchronizationFailException(const std::string &source, Exception* innerException) : Exception(source, innerException) {}
    SensorSynchronizationFailException(const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(message, code) {}
    SensorSynchronizationFailException(const std::string &source, const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code) {}
    SensorSynchronizationFailException(const std::string &source, const std::string &message, Exception *innerException, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code, innerException) {}
    ~SensorSynchronizationFailException(){}
};


/**
 * @class SensorResetFailException
 * @brief Exception for sensor reset failures.
 *
 * Use this exception to indicate errors during sensor reset operations.
 */
class SensorResetFailException : public Exception
{
public:
    SensorResetFailException(const std::string &source, Exception* innerException) : Exception(source, innerException) {}
    SensorResetFailException(const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(message, code) {}
    SensorResetFailException(const std::string &source, const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code) {}
    SensorResetFailException(const std::string &source, const std::string &message, Exception *innerException, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code, innerException) {}
    ~SensorResetFailException(){}
};


/**
 * @class SensorConnectFailException
 * @brief Exception for sensor connection failures.
 *
 * Use this exception to indicate errors during sensor connection operations.
 */
class SensorConnectFailException : public Exception
{
public:
    SensorConnectFailException(const std::string &source, Exception* innerException) : Exception(source, innerException) {}
    SensorConnectFailException(const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(message, code) {}
    SensorConnectFailException(const std::string &source, const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code) {}
    SensorConnectFailException(const std::string &source, const std::string &message, Exception *innerException, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code, innerException) {}
    ~SensorConnectFailException(){}
};


/**
 * @class SensorDisconnectFailException
 * @brief Exception for sensor disconnection failures.
 *
 * Use this exception to indicate errors during sensor disconnection operations.
 */
class SensorDisconnectFailException : public Exception
{
public:
    SensorDisconnectFailException(const std::string &source, Exception* innerException) : Exception(source, innerException) {}
    SensorDisconnectFailException(const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(message, code) {}
    SensorDisconnectFailException(const std::string &source, const std::string &message, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code) {}
    SensorDisconnectFailException(const std::string &source, const std::string &message, Exception *innerException, ErrorCode code = ErrorCode::CRITICAL_ERROR_CODE) : Exception(source, message, code, innerException) {}
    ~SensorDisconnectFailException(){}
};

#endif // SENSORS_EXCEPTIONS_HPP