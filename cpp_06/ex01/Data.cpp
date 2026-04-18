#include "Data.hpp"

Data::Data() : userId(0)
{
}

Data::Data(const Data &other) : userId(other.userId)
{
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		userId = other.userId;
	}
	return *this;
}

Data::~Data()
{
}

int Data::getUserId() const
{
	return userId;
}

void Data::setUserId(int id)
{
	userId = id;
}