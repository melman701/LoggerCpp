/**
 * @file    Logger.cpp
 * @ingroup LoggerCpp
 * @brief   A simple thread-safe Logger class
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include "Logger.h"
#include "Manager.h"

#include <cassert>


namespace Log
{


/**
 * @brief Initialize a Logger utility object
 *
 * @param[in] apChannelName    String to identify origin of Log output by this Logger
 */
Logger::Logger(const char* apChannelName)
{
    assert(NULL != apChannelName);

    mChannelPtr = Manager::get(apChannelName);

    assert(mChannelPtr);
}

Logger::~Logger(void)
{
}


// Utility const method to produce Log objets, used to collect the stream to output
Log Logger::debug(void) const
{
    return Log(*this, Log::eDebug);
}
Log Logger::info(void) const
{
    return Log(*this, Log::eInfo);
}
Log Logger::notice(void) const
{
    return Log(*this, Log::eNotice);
}
Log Logger::warning(void) const
{
    return Log(*this, Log::eWarning);
}
Log Logger::error(void) const
{
    return Log(*this, Log::eError);
}
Log Logger::critic(void) const
{
    return Log(*this, Log::eCritic);
}


/**
 * @brief Output the Log. Used by the Log class destructor.
 *
 * @param[in] aLog  The Log to output
 */
void Logger::output(const Log& aLog) const
{
    Manager::output(mChannelPtr, aLog);
}


} // namespace Log

