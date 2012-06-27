#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <typeinfo.h>

class TypeInfo
{
public:
	explicit TypeInfo(const type_info& info) : _typeInfo(info) {};

	bool operator < (const TypeInfo& rhs) const
	{
		return _typeInfo.before(rhs._typeInfo) != 0;
	}

private:
	const type_info& _typeInfo;
};

#endif