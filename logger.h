#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Logging
{
	class Logger 
	{
	public:
		std::string* messages;

		Logger(const int maxMessagesCount = 25);
		~Logger();

		void Log(const std::string& message);
		int  GetMaxMessagesCount();

	private:
		int messagesArraySize = 0;
		int messageIndex = 0;
	};
}