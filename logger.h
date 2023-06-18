
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <vector>

namespace Logging
{
	class Logger 
	{
	public:
		std::string* messages;

		Logger(const int maxMessagesCount = 10);
		~Logger();

		void Log(const std::string& message);
		int  GetMaxMessagesCount();

	private:
		int messagesArraySize = 0;
		int messageIndex = 0;
	};
}

#endif