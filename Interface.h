#pragma once
#include "Rectangle.h"


class Interface
{
public:
	Interface();
	~Interface();

	void Init() const;
private:
	void EditRectangle() const;
	void CreateRectangle () const;
	void DeleteRectangle(const std::string name) const;
	void DelRectangle() const;
	void Help() const;
	int GetIndex(const std::string name) const;
	void PrintRectangle() const;
	void Area() const;
	void Move() const;
	void Build() const;
	void PrintAllRec() const;

	std::string* _names = nullptr;
	Rectangle* _cases = nullptr;
};