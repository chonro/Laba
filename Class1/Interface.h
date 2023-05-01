#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

namespace isp 
{
template <typename T>
class IObject 
{
public:
	virtual ~IObject() = default;
	virtual std::string to_string() const = 0;
	//virtual void swap(T&) = 0;
	virtual T& assign(const T&) = 0;
	//virtual T& copy() = 0;
	virtual void dispose() = 0;
	virtual int cmp(const T&) = 0;

};



}


#endif // !INTERFACE_H
