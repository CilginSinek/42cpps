#ifndef _DATA_HPP_
#define _DATA_HPP_

class Data
{
public:
	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();

	//* Getter and Setter for userId
	int getUserId() const;
	void setUserId(int id);

private:
	int userId;
};

#endif