#include <iostream>
#include <string>

class IBusinessMenu
{
protected:
	virtual const char* GetFirstItem()  =0 ;
	virtual const char* GetSecondItem() =0;
	virtual const char* GetCompot() =0 ;
public:
	void PrintMenu()
	{
		std::cout << "Menu:" << std::endl;
		if (GetFirstItem() != nullptr) std::cout << "Item:" << GetFirstItem() << std::endl;
		if (GetSecondItem() != nullptr) std::cout << "Item:" << GetSecondItem() << std::endl;
		if (GetCompot() != nullptr) std::cout << "Item:" << GetCompot() << std::endl;
	}
};

class BusinessMenu :  public IBusinessMenu
{
	private:
		std::string first;
		std::string second;
		std::string compot;
	protected:
		 const char* GetFirstItem() override { return first.c_str(); };
		 const char* GetSecondItem() override { return second.c_str(); };
		 const char* GetCompot() override { return compot.c_str(); };
	public:
		BusinessMenu(std::string a, std::string b, std::string c) : first(a), second(b), compot(c) {};

};

class CoffeMenu : public IBusinessMenu
{
private:
	std::string coffe;
	std::string bulka;
protected:
	 const char* GetFirstItem() override { return coffe.c_str(); };
	 const char* GetSecondItem() override { return bulka.c_str(); };
	 const char* GetCompot() override { return nullptr; }; // ненужный метод!
public:
	CoffeMenu(std::string a, std::string b) : coffe(a), bulka(b) {};
};


auto main() -> int
{
	BusinessMenu menu("Borshhh", "Makaroni", "Vishneviy kompot");
	CoffeMenu    coffe("Latte", "Bublik");


	//IBusinessMenu *ptr = &menu;
	//foo(ptr);
	
	menu.PrintMenu();
	coffe.PrintMenu();

	return 0;
}

