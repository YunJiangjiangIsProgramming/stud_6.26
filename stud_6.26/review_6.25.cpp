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

	size_t pos1 = s1.find('.');//find()�ҵ�����λ��
	if (pos1 != string::npos)//npos unsigned int -1ת��int���Ǽ�ʮ�ڴ�
	{
		cout << s1.substr(pos1) << endl;

	}
	size_t pos2 = s2.find('.');//find()�ҵ�����λ��
	if (pos2 != string::npos)//npos unsigned int -1ת��int���Ǽ�ʮ�ڴ�
	{
		cout << s2.substr(pos2) << endl;

	}
	size_t pos3 = s3.find('.');//find()�ҵ�����λ��
	if (pos3 != string::npos)//npos unsigned int -1ת��int���Ǽ�ʮ�ڴ�
	{
		cout << s3.substr(pos3) << endl;//substr(1,2)1����ʼλ��2�ǳ���q

	}
}

void test_string9()
{
	string url("https://www.tiangong.cn/chat/coder/022");
	//����������Э��������Դ����
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
		// �ҵ����һ���ո��λ��
		size_t pos = s.rfind(' ');

		// ���û���ҵ��ո�˵�������ַ�������һ������
		if (pos == std::string::npos) {
			return s.size();
		}

		// ����β���Ŀո�
		while (pos == s.size() - 1) {
			s.pop_back(); // �Ƴ��ַ���ĩβ�Ŀո�
			pos = s.rfind(' '); // �������һ���ո��λ��
			if (pos == std::string::npos) {
				return 0; // ���ȥ�����пո���ַ���Ϊ�գ�����0
			}
		}

		// �������һ�����ʵĳ���
		return s.size() - pos - 1;
		
	}
};

class Solution1 {
public:
	int lengthOfLastWord(string s) {
		// ȥ���ַ���ĩβ�Ŀո�
		while (!s.empty() && s.back() == ' ') {
			s.pop_back(); // �Ƴ��ַ���ĩβ�Ŀո�
		}

		// ����ַ�������Ϊ�գ�˵��ԭʼ�ַ���ȫ���ǿո�
		if (s.empty()) {
			return 0;
		}

		// �ҵ����һ���ո��λ��
		size_t pos = s.rfind(' ');

		// ���û���ҵ��ո�˵�������ַ�������һ������
		if (pos == std::string::npos) {
			return s.size();
		}

		// �������һ�����ʵĳ���
		return s.size() - pos - 1;
	}
};

//int main()
//{
//	string s;
//	//cin >> si;//cin���յ��ո���߻��оͻ����������getline����getlineֻ�н��ܵ����вŻ����
//	getline(cin, s);
//	/*size_t pos = s.rfind(' ');
//	cout << s.size() - (pos + 1) << endl;*/
//	
//	return 0;
//}

//����һ���ַ��� s ����֤ s �Ƿ��� ���Ĵ� ��ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//ʾ�� 1:
//
//����: s = "A man, a plan, a canal: Panama"
//��� : true
//���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ�
//ʾ�� 2 :
//
//	���� : s = "race a car"
//	��� : false
//	���ͣ�"raceacar" ���ǻ��Ĵ�
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
			//���������ַ��������д�дת����Сд Ҫ��&������Ȼ
			for (auto& ch : s)              //�����s�е�ֵ�ĵ��ǿ����Ĵ�
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
			// ֻ������ĸ�������ַ�
			if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
				return true;
			}
			else {
				return false;
			}
		}

		bool isPalindrome(string s)
		{
			// �����д�д��ĸת��ΪСд
			for (auto& ch : s) {
				if (ch >= 'A' && ch <= 'Z') {
					ch += 32;
				}
			}

			int begin = 0, end = s.size() - 1;
			while (begin < end) {
				// ��������ĸ�����ַ�
				while (!isCharorNumber(s[begin]) && begin < end) {
					++begin;
				}
				while (!isCharorNumber(s[end]) && begin < end) {
					--end;
				}

				// ��������ַ�����ͬ������ false
				if (s[begin] != s[end]) {
					return false;
				}
				else {
					// �ƶ�ָ�룬�����Ƚ���һ���ַ�
					++begin;
					--end;
				}
			}

			// ��������ַ������ɹ�ƥ�䣬��ô����һ�����Ĵ�
			return true;
		}
	};

	class Solution4 {
	public:
		int strToInt(string str) {
			if (str.empty()) return 0;
			int index = 0, n = str.size(), sign = 1, res = 0;
			// ����ǰ�ÿո�
			while (index < n && str[index] == ' ') {
				++index;
			}
			// �������
			if (index < n && (str[index] == '+' || str[index] == '-')) {
				sign = str[index++] == '+' ? 1 : -1;
			}
			// ��������
			while (index < n && isdigit(str[index])) {
				int digit = str[index] - '0';
				// �ж��Ƿ����
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
			while (end1 >= 0 || end2 >= 0)//ֻҪ����ֵ����Ϊ0,����ͻ������·
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


	class Solution6//�ַ������
	{
	public:
		string addStrings(string num1, string num2) {
			// ��ʼ������ָ��ֱ�ָ��num1��num2��ĩβ
			int end1 = num1.size() - 1;
			int end2 = num2.size() - 1;

			// ��λ��ʼ��Ϊ0
			int next = 0;

			// ���ڴ洢������ַ���
			string retstr;

			// ����Ƿ��г�ʼ�Ľ�λ��Ҫ����
			if (next == 1 && end1 >= 0) {
				// ��num1�����һλ�ַ�ת��Ϊ���֣���1
				num1[end1] += 1;

				// �����1�����'9'������Ҫ��λ��������ǰλ��ȥ10
				if (num1[end1] > '9') {
					num1[end1] -= 10;
					next = 1; // ���ý�λΪ1
				}
				else {
					next = 0; // ���û�н�λ������λ����Ϊ0
				}
			}

			// ѭ�����������ַ�����ÿһλ��ֱ�������ַ�����������ϲ���û�н�λ
			while (end1 >= 0 || end2 >= 0 || next == 1) {
				int val1 = 0; // num1��ǰλ������
				int val2 = 0; // num2��ǰλ������

				// ���end1 >= 0��˵��num1����λ���ã�����ת��Ϊ����
				if (end1 >= 0) {
					val1 = num1[end1] - '0'; // ת��Ϊ���֣�'0'��ASCIIֵ��48�����Լ�ȥ'0'�õ�ʵ�ʵ�����
				}

				// ���end2 >= 0��˵��num2����λ���ã�����ת��Ϊ����
				if (end2 >= 0) {
					val2 = num2[end2] - '0'; // ͬ��ת��Ϊ����
				}

				// ���㵱ǰλ�ĺͲ����Ͻ�λ
				int ret = val1 + val2 + next;

				// ����ʹ���9����Ҫ��λ������ȥ10�õ���ǰλ������
				if (ret > 9) {
					ret -= 10;
					next = 1;
				}
				else {
					next = 0;
				}

				// �����ת��Ϊ�ַ���ӵ�����ַ�����
				retstr += ret + '0'; // �����ּ���'0'ת��Ϊ�ַ�

				// �ƶ�����ָ�뵽��һλ
				--end1;
				--end2;
			}

			// ���������ǴӺ���ǰ�ӵģ����Խ���ַ�����Ҫ��ת
			reverse(retstr.begin(), retstr.end());
			return retstr;
		}
	};

	class Solution7 //�ַ������
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