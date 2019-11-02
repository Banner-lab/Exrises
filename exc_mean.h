#ifndef EXC_MEAN_H_
#define WXC_MEAN_H_
#include <iostream>
#include <stdexcept>
using namespace std;
class bad_bmean:public  logic_error
{
public:
   explicit	 bad_bmean(const string& bad) :logic_error(bad) { }

};

class bad_gmean :public logic_error
{
public:
	explicit  bad_gmean(const string& bad) :logic_error(bad) { }
};




#endif // !EXC_MEAN_H-
