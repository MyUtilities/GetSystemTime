#include "CTime.h"

template<class time_data_type> 
CTime<time_data_type>::CTime()
{

}

template<> CTime<unsigned long long>::CTime(){}
template<> CTime<unsigned long long>::~CTime(){}

template<> CTime<time_t>::CTime(){}
template<> CTime<time_t>::~CTime(){}

template<> CTime<tm*>::CTime(){}
template<> CTime<tm*>::~CTime(){}

template<> CTime<std::chrono::time_point<std::chrono::system_clock>>::CTime(){}
template<> CTime<std::chrono::time_point<std::chrono::system_clock>>::~CTime(){}

template<>
int CTime<int>::Get_System_Time()
{
	return 0;
}

template<>
float CTime<float>::Get_System_Time()
{
	return 0;
}

template<>
time_t CTime<time_t>::Get_System_Time()
{
	std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
	time_t out_time_t = std::chrono::system_clock::to_time_t(p);
	return out_time_t;
}

template<>
tm* CTime<tm*>::Get_System_Time()
{
	std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(p);
	struct tm * out_tm = localtime(&t);	
	return out_tm;
}

template<>
unsigned long long CTime<unsigned long long>::Get_System_Time()
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	unsigned long long out_long_millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	return out_long_millis;
}

template<> 
std::chrono::time_point<std::chrono::system_clock> CTime<std::chrono::time_point<std::chrono::system_clock>>::Get_System_Time()
{
	std::chrono::time_point<std::chrono::system_clock> out_time_point = std::chrono::system_clock::now();
	return out_time_point;
}
