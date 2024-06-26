#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void test_string8()
{
	string s1("string.cpp");
	string s2("string.c");
	string s3;

	size_t pos1 = s1.find('.');//find()找到返回位置
	if (pos1 != string::npos)//npos unsigned int -1转成int就是几十亿大
	{
		cout << s1.substr(pos1) << endl;

	}
	size_t pos2 = s2.find('.');//find()找到返回位置
	if (pos2 != string::npos)//npos unsigned int -1转成int就是几十亿大
	{
		cout << s2.substr(pos2) << endl;

	}
	size_t pos3 = s3.find('.');//find()找到返回位置
	if (pos3 != string::npos)//npos unsigned int -1转成int就是几十亿大
	{
		cout << s3.substr(pos3) << endl;//substr(1,2)1是起始位置2是长度q

	}
}

void test_string9()
{
	string url("https://www.tiangong.cn/chat/coder/022");
	//分离出上面的协议域名资源名称
	size_t i1 = url.find(':');
	if (i1 != string::npos)
	{
		cout << url.substr(0, i1) << endl;

	}
	size_t i2 = url.find('/',i1+3);
	if (i2 != string::npos)
	{
		cout << url.substr(i1+3, i2-(i1+3)) << endl;

	}
	cout << url.substr(i2 + 1) << endl;


}

class Solution0 {
public:
	int lengthOfLastWord(string s) {
		// 找到最后一个空格的位置
		size_t pos = s.rfind(' ');

		// 如果没有找到空格，说明整个字符串都是一个单词
		if (pos == std::string::npos) {
			return s.size();
		}

		// 跳过尾部的空格
		while (pos == s.size() - 1) {
			s.pop_back(); // 移除字符串末尾的空格
			pos = s.rfind(' '); // 更新最后一个空格的位置
			if (pos == std::string::npos) {
				return 0; // 如果去掉所有空格后字符串为空，返回0
			}
		}

		// 计算最后一个单词的长度
		return s.size() - pos - 1;
		
	}
};

class Solution1 {
public:
	int lengthOfLastWord(string s) {
		// 去除字符串末尾的空格
		while (!s.empty() && s.back() == ' ') {
			s.pop_back(); // 移除字符串末尾的空格
		}

		// 如果字符串现在为空，说明原始字符串全部是空格
		if (s.empty()) {
			return 0;
		}

		// 找到最后一个空格的位置
		size_t pos = s.rfind(' ');

		// 如果没有找到空格，说明整个字符串都是一个单词
		if (pos == std::string::npos) {
			return s.size();
		}

		// 计算最后一个单词的长度
		return s.size() - pos - 1;
	}
};

//int main()
//{
//	string s;
//	//cin >> si;//cin接收到空格或者换行就会结束可以用getline（）getline只有接受到换行才会结束
//	getline(cin, s);
//	/*size_t pos = s.rfind(' ');
//	cout << s.size() - (pos + 1) << endl;*/
//	
//	return 0;
//}

//给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。
//示例 1:
//
//输入: s = "A man, a plan, a canal: Panama"
//输出 : true
//解释："amanaplanacanalpanama" 是回文串
//示例 2 :
//
//	输入 : s = "race a car"
//	输出 : false
//	解释："raceacar" 不是回文串
	class Solution2 {
	public:
		bool isCharorNumber(char ch)
		{
			if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		bool isPalindrome(string s)
		{
			//遍历整个字符串将所有大写转化成小写 要用&别名不然
			for (auto& ch : s)              //不会改s中的值改的是拷贝的串
			{
				if (ch >= 'A' && ch <= 'Z')
				{
					ch += 32;
				}

			}
			int begin = 0, end = s.size() - 1;
			while (begin < end)
			{
				while (isCharorNumber(s[begin]) && begin < end)
				{
					++begin;
				}
				while (isCharorNumber(s[end]) && begin < end)
				{
					--end;
				}
				if (s[begin] != s[end])
				{
					return false;
				}
				else
				{
					++begin;
					--end;
				}

			}

			return true;


		}
}; 

	class Solution3 {
	public:
		bool isCharorNumber(char ch)
		{
			// 只接受字母和数字字符
			if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
				return true;
			}
			else {
				return false;
			}
		}

		bool isPalindrome(string s)
		{
			// 将所有大写字母转换为小写
			for (auto& ch : s) {
				if (ch >= 'A' && ch <= 'Z') {
					ch += 32;
				}
			}

			int begin = 0, end = s.size() - 1;
			while (begin < end) {
				// 跳过非字母数字字符
				while (!isCharorNumber(s[begin]) && begin < end) {
					++begin;
				}
				while (!isCharorNumber(s[end]) && begin < end) {
					--end;
				}

				// 如果两个字符不相同，返回 false
				if (s[begin] != s[end]) {
					return false;
				}
				else {
					// 移动指针，继续比较下一对字符
					++begin;
					--end;
				}
			}

			// 如果所有字符都被成功匹配，那么这是一个回文串
			return true;
		}
	};

	class Solution4 {
	public:
		int strToInt(string str) {
			if (str.empty()) return 0;
			int index = 0, n = str.size(), sign = 1, res = 0;
			// 处理前置空格
			while (index < n && str[index] == ' ') {
				++index;
			}
			// 处理符号
			if (index < n && (str[index] == '+' || str[index] == '-')) {
				sign = str[index++] == '+' ? 1 : -1;
			}
			// 处理数字
			while (index < n && isdigit(str[index])) {
				int digit = str[index] - '0';
				// 判断是否溢出
				if (res > (INT_MAX - digit) / 10) {
					return sign == 1 ? INT_MAX : INT_MIN;
				}
				res = res * 10 + digit;
				++index;
			}
			return res * sign;
		}
	};


	class Solution5 {
	public:
		string addStrings(string num1, string num2)
		{
			int end1 = num1.size() - 1;
			int end2 = num2.size() - 1;
			int next = 0;
			string retstr;
			while (end1 >= 0 || end2 >= 0)//只要两个值都不为0,程序就会继续走路
			{
				int val1 = 0;
				int val2 = 0;
				if (end1 >= 0)
				{
					val1 = num1[end1] - '0';
				}
				if (end2 >= 0)
				{
					val2 = num2[end1] - '0';
				}
				int ret = val1 + val2 + next;
				if (ret > 9)
				{
					ret -= 10;
					next = 1;
				}
				else
				{
					next = 0;
				}
				if (next == 1)
				{
					retstr += '1';
				}
				reverse(retstr.begin(), retstr.end());
				--end1;
				--end2;
			}

			return retstr;
		}
	};


	class Solution6//字符串相乘
	{
	public:
		string addStrings(string num1, string num2) {
			// 初始化两个指针分别指向num1和num2的末尾
			int end1 = num1.size() - 1;
			int end2 = num2.size() - 1;

			// 进位初始化为0
			int next = 0;

			// 用于存储结果的字符串
			string retstr;

			// 检查是否有初始的进位需要处理
			if (next == 1 && end1 >= 0) {
				// 将num1的最后一位字符转换为数字，加1
				num1[end1] += 1;

				// 如果加1后大于'9'，则需要进位，并将当前位减去10
				if (num1[end1] > '9') {
					num1[end1] -= 10;
					next = 1; // 设置进位为1
				}
				else {
					next = 0; // 如果没有进位，将进位设置为0
				}
			}

			// 循环处理两个字符串的每一位，直到两个字符串都处理完毕并且没有进位
			while (end1 >= 0 || end2 >= 0 || next == 1) {
				int val1 = 0; // num1当前位的数字
				int val2 = 0; // num2当前位的数字

				// 如果end1 >= 0，说明num1还有位可用，将其转换为数字
				if (end1 >= 0) {
					val1 = num1[end1] - '0'; // 转换为数字，'0'的ASCII值是48，所以减去'0'得到实际的数字
				}

				// 如果end2 >= 0，说明num2还有位可用，将其转换为数字
				if (end2 >= 0) {
					val2 = num2[end2] - '0'; // 同样转换为数字
				}

				// 计算当前位的和并加上进位
				int ret = val1 + val2 + next;

				// 如果和大于9，需要进位，并减去10得到当前位的数字
				if (ret > 9) {
					ret -= 10;
					next = 1;
				}
				else {
					next = 0;
				}

				// 将结果转换为字符添加到结果字符串中
				retstr += ret + '0'; // 将数字加上'0'转换为字符

				// 移动两个指针到下一位
				--end1;
				--end2;
			}

			// 由于我们是从后往前加的，所以结果字符串需要反转
			reverse(retstr.begin(), retstr.end());
			return retstr;
		}
	};

	class Solution7 //字符串相乘
	{
	public:
		string multiply(string num1, string num2) {
			if (num1 == "0" || num2 == "0") return "0";
			vector<int> result(num1.size() + num2.size(), 0);
			for (int i = 0; i < num1.size(); i++) {
				for (int j = 0; j < num2.size(); j++) {
					result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
				}
			}
			for (int i = result.size() - 1; i > 0; i--) {
				if (result[i] < 10) continue;
				result[i - 1] += result[i] / 10;
				result[i] %= 10;
			}
			string res = "";
			bool zero = true;
			for (auto r : result) {
				if (zero && r == 0) continue;
				zero = false;
				res.push_back(r + '0');
			}
			return res;
		}
	};

	
int main()
{
	//test_string8();
	/*test_string9();*/

	class Solution4;
	class Solution6;


	return 0;
}