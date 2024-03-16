#include <string>

template<typename T>
class Result {
public:
	T unwrap();
	bool is_ok() { return err.length() == 0 ? true : false; }
private:
	T result;
	std::string err;
};
