#include<assert.h>
#define Max_INT64 9223372036854775807
#define Min_INT64 (-9223372036854775808)
//不能直接用-9223372036854775808，当编译器看到9223372036854775808时直接判定
//9223372036854775808>INT64_MAX,直接用unsigned int64表示。当编译器看到负号时，
//直接对9223372036854775808取反，直接是它本身，编译器存不了那么大的数，报错
#define INT64 long long int
using namespace std;

class BigData
{
public:
	BigData(INT64 data);
	BigData(const char *str);
	BigData operator+(BigData& d);
	BigData operator-(BigData& d);
	BigData operator*(BigData& d);
	BigData operator/(BigData& d);
private:
	friend string Add(string& left, string& right);
	friend string Sub(string& left, string& right);
	friend string Mul(string& left, string& right);
	friend string Div(string& left, string& right);
	bool _IsINT64OverFlow()const;
	friend ostream& operator<<(ostream& _cout, const BigData& d);
	void _INT64ToString();
private:
	string _strvalue;
	INT64 _value;
};

#endif

