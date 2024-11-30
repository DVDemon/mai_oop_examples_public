#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>


int main()
{
	std::vector<int> elements;

    for(int i=0;i<10;i++) elements.push_back(i);
	std::function<void (int)> trace_lambda = [] (int i) { std::cout << i << " ";};

	for (auto &ee : elements) trace_lambda(ee);
	std::cout << std::endl;

	auto lambda_gen = [] (int i)  -> std::function<int (int)>
	{
		if(i<10) return [i](int n) -> int { return i + n;};
			else return [i](int n) -> int { return i - n;};
	};

	std::cout << lambda_gen(25)(5) << std::endl;

	auto lll = lambda_gen(0);

	std::transform(elements.begin(),elements.end(),
				   elements.begin(),
				   lll);
	for (auto &ee : elements) trace_lambda(ee);

        
	std::cout << std::endl;

	return 0;

}