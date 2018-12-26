#pragma once
#include <chrono>
#include <string>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sys/time.h>
#include <unistd.h>
template<class time_data_type> class CTime 
{
public:
	CTime();
	~CTime();	
	
	time_data_type Get_System_Time();
	void Set_System_Time(unsigned long long seconds);
};
