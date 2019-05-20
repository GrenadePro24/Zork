#ifndef Command_
#define Command_

#include <string>
using namespace std;
class Command
{
	public:
		Command(string action, string targetA, string conjunction, string targetB);
		~Command();
	public :
		string action;
		string targetA;
		string conjunction;
		string targetB;
};

#endif

