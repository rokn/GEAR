#ifndef GEAR_HELPER_H
#define GEAR_HELPER_H

#include <string>
#include <algorithm>

namespace GEAR
{
	class HL
	{
	public:
	
		////////////////////////////////////////////////////////////
		/// \brief Removes all white spaces from a string
		///
		/// \param str The string to modify
		////////////////////////////////////////////////////////////
		static void RemoveWhiteSpaces(std::string& str)
		{
			str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
		}
	
		////////////////////////////////////////////////////////////
		/// \brief Try to convert a string to integer
		///
		/// \param str The string to parse.
		/// \param result Holds the parsed int.
		///
		/// \return Returns true on success and false on error.
		///
		////////////////////////////////////////////////////////////
		static bool TryToInt(const std::string& str, int& result)
		{
			std::string copy = str;
			RemoveWhiteSpaces(copy);
			result = 0;
			bool res = true;
			bool negative = (copy[0] == '-');
			
			int startPos = (negative) ? 1 : 0;
			
			for(unsigned int i = startPos; i < copy.length(); ++i)
			{
				if(copy[i] >= '0' && copy[i] <= '9')
				{
					result *= 10;
					result += copy[i] - '0';
				}
				else
				{
					result = 0;
					res = false;
					break;
				}
			}
			
			if(negative)
				result *= -1;
			
			return res;
		}
		
		////////////////////////////////////////////////////////////
		/// \brief Try to convert a string to bool
		///
		/// \param str The string to parse.
		/// \param result Holds the parsed bool.
		///
		/// \return Returns true on success and false on error.
		///
		////////////////////////////////////////////////////////////
		static bool TryToBool(const std::string& str, bool& result)
		{
//			std::stod(str);
			bool res = false;
			result = false;
			std::string copy = str;
			std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
			
			if(copy.compare("true") || copy.compare("1"))
			{
				res = true;
				result = true;
			}
			else if (copy.compare("false") || copy.compare("0"))
			{
				res = true;
			}
				
			return res;
		}
		
		
		
	};
}


#endif //GEAR_HELPER_H