#pragma once
#include <chrono>
#include <string>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

template<class time_data_type> class CTime 
{
public:
	CTime();
	~CTime();	
	
	time_data_type Get_System_Time();
};
