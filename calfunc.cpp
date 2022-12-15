#include "calfunc.h"
#include<string>
using namespace std;
string calfunc::Sum(string a, string s) {
	string afirst, alast, sfirst, slast;
	bool dot1 = false, dot2 = false;
	int k, length1, length2, location1, location2;
	length1 = a.size();
	length2 = s.size();
	for (int i = 0; i < length1; i++) {
		if (a[i] == '.') {
			location1 = i;
			dot1 = true;
		}
	}
	if (dot1 == false) {
		a = a.replace(a.size(), 0, ".0");
		location1 = length1;
	}
	afirst = a.substr(0, location1);
	alast = a.substr(location1 + 1, a.size());
	for (int i = 0; i < length2; i++) {
		if (s[i] == '.') {
			dot2 = true;
			location2 = i;
		}
	}
	if (dot2 == false) {
		s = s.replace(s.size(), 0, ".0");
		location2 = length2;
	}
	sfirst = s.substr(0, location2);
	slast = s.substr(location2 + 1, s.size());
	if (afirst.length() > sfirst.length())
		swap(afirst, sfirst);
	for (int i = 1; i <= afirst.length(); i++) {
		k = sfirst[sfirst.length() - i] + afirst[afirst.length() - i] - 48;
		if (k >= 58)
		{
			if (i == sfirst.length()) {
				sfirst = sfirst.replace(0, 0, "0");
			}
			sfirst[sfirst.length() - i - 1]++;
			sfirst[sfirst.length() - i] = k - 10;
		}
		else
			sfirst[sfirst.length() - i] = k;
	}
	if (alast.length() > slast.length())
		swap(alast, slast);
	for (int i = 1; i <= alast.length(); i++) {
		k = slast[slast.length() - i] + alast[alast.length() - i] - 48;
		if (k >= 58)
		{
			if (i == alast.length()) {
				if (k >= 58) {
					sfirst[sfirst.length() - 1]++;
					slast[slast.length() - i] = k - 10;
				}
			}
			else {
				slast[slast.length() - i - 1]++;
				slast[slast.length() - i] = k - 10;
			}
		}
		else
			slast[slast.length() - i] = k;
	}
	for (int i = slast.length() - 1; i >= 0; i--) {
		if (slast[i] == '0') {
			slast.erase(i, i + 1);
		}
	}

	s = sfirst + slast;
	s = s.replace(sfirst.size(), 0, ".");
	if (s[s.size() - 1] == '.') {
		s.erase(s.size() - 1, s.size());
	}
	return s;
}
string calfunc::Minus(string a, string s) {
	string afirst, alast, sfirst, slast, mine, mine1, Mine;
	bool dot1 = false, dot2 = false;
	int k, sign = 1, length1, length2, location1, location2;
	length1 = a.size();
	length2 = s.size();
	for (int i = 0; i < length1; i++) {
		if (a[i] == '.') {
			location1 = i;
			dot1 = true;
		}
	}
	if (dot1 == false) {
		a = a.replace(a.size(), 0, ".0");
		location1 = length1;
	}
	afirst = a.substr(0, location1);
	alast = a.substr(location1 + 1, a.size());
	if (a[0] == '-') {
		alast = alast.replace(0, 0, "-");
	}
	for (int i = 0; i < length2; i++) {
		if (s[i] == '.') {
			dot2 = true;
			location2 = i;
		}
	}
	if (dot2 == false) {
		s = s.replace(s.size(), 0, ".0");
		location2 = length2;
	}
	sfirst = s.substr(0, location2);
	slast = s.substr(location2 + 1, s.size());
	if (s[0] == '-') {
		slast = slast.replace(0, 0, "-");
	}
	int afl = afirst.size(), sfl = sfirst.size();
	if (afirst[0] == '-' && sfirst[0] == '-') {
		if (afirst.size() > sfirst.size()) {
			swap(afirst, sfirst);
			swap(afl, sfl);
			sign = -1;
		}
		if (afirst.size() == sfirst.size()) {
			for (int i = 0; i < afirst.size(); i++) {
				if (afirst[i] != sfirst[i] && afirst[i] > sfirst[i]) {
					swap(afirst, sfirst);
					swap(afl, sfl);
					sign = -1;
				}
				if (afirst[i] != sfirst[i] && afirst[i] < sfirst[i]) {
					break;
				}
			}
		}
		for (int i = 1; i < afirst.size(); i++)
		{
			k = sfirst[sfirst.size() - i] - afirst[afirst.size() - i] + 48;
			if (k < '0')
			{
				sfirst[sfirst.size() - i - 1]--;
				sfirst[sfirst.size() - i] = k + 10;
			}
			else
				sfirst[sfirst.size() - i] = k;
		}
		if (sign == -1) {
			mine[0] = '-';
			mine.replace(0, sfirst.size(), sfirst);
			if (mine[0] == '-') {
				while (mine[1] == '0') {
					mine.erase(1, 1);
				}
			}
			else {
				while (mine[0] == '0') {
					mine.erase(0, 1);
				}
			}
		}
		else {
			mine = sfirst;
			if (mine[0] == '-') {
				while (mine[1] == '0') {
					mine.erase(1, 2);
				}
				if (mine.size() == 1) {
					mine[0] = '0';
				}
			}
			else {
				while (mine[0] == '0') {
					mine.erase(0, 0);
				}
				if (mine.size() == 0) {
					mine[0] = '0';
				}
			}
		}

	}
	else if (afirst[0] != '-' && sfirst[0] != '-') {
		if (afirst.size() > sfirst.size()) {
			swap(afirst, sfirst);
			swap(afl, sfl);
		}
		else if (afirst.size() < sfirst.size()) {
			sign = -1;
		}
		else if (afirst.size() == sfirst.size()) {
			for (int i = 0; i < afirst.size(); i++) {
				if (afirst[i] != sfirst[i] && afirst[i] > sfirst[i]) {
					swap(afirst, sfirst);
					swap(afl, sfl);
					break;
				}
				else if (afirst[i] != sfirst[i] && afirst[i] < sfirst[i]) {
					sign = -1;
					break;
				}
			}
		}
		for (int i = 1; i <= afirst.size(); i++)
		{
			k = sfirst[sfirst.size() - i] - afirst[afirst.size() - i] + 48;
			if (k < '0')
			{
				sfirst[sfirst.size() - i - 1]--;
				sfirst[sfirst.size() - i] = k + 10;
			}
			else
				sfirst[sfirst.size() - i] = k;
		}
		while (sfirst[0] == '0') {
			sfirst.erase(0, 1);
		}
		if (sign == -1) {
			mine.replace(0, sfirst.size(), sfirst);
			mine.replace(0, 0, "-");
			if (mine[0] == '-') {
				while (mine[1] == '0') {
					mine.erase(1, 2);
				}
				if (mine.size() == 1) {
					mine[0] = '0';
				}
			}
			else {
				while (mine[0] == '0') {
					mine.erase(0, 1);
				}
				if (mine.size() == 0) {
					mine[0] = '0';
				}
			}
		}
		else {
			mine = sfirst;
			if (mine[0] == '-') {
				while (mine[1] == '0') {
					mine.erase(1, 2);
				}
				if (mine.size() == 1) {
					mine[0] = '0';
				}
			}
			else {
				while (mine[0] == '0') {
					mine.erase(0, 1);
				}
				if (mine.size() == 1) {
					if (mine[0] == '-') {
						mine[0] = '0';
					}
				}
			}
		}
	}
	else {
		if (afirst[0] != '-' && sfirst[0] == '-') {
			if (afirst.size() > sfirst.size()) {
				swap(afirst, sfirst);
				swap(afl, sfl);
			}
			for (int i = 1; i <= afirst.size(); i++) {
				k = afirst[afirst.size() - i] + sfirst[sfirst.size() - i] - 48;
				if (k >= 58)
				{
					sfirst[sfirst.size() - i - 1]++;
					sfirst[sfirst.size() - i] = k - 10;
				}
				else
					sfirst[afirst.size() - i] = k;
			}
			if (sfirst[0] == '-') {
				mine.replace(0, sfirst.size(), sfirst);
				mine.erase(0, 1);
				if (mine[0] == '-') {
					while (mine[1] == '0') {
						mine.erase(1, 2);
					}
					if (mine.size() == 1) {
						mine[0] = '0';
					}
				}
				else {
					while (mine[0] == '0') {
						mine.erase(0, 1);
					}
					if (mine.size() == 0) {
						mine[0] = '0';
					}
				}
			}
			else {
				mine = sfirst;
				if (mine[0] == '-') {
					while (mine[1] == '0') {
						mine.erase(1, 2);
					}
					if (mine.size() == 1) {
						mine[0] = '0';
					}
				}
				else {
					if (mine[0] == '-') {
						while (mine[1] == '0') {
							mine.erase(1, 2);
						}
						if (mine.size() == 1) {
							mine[0] = '0';
						}
					}
					else {
						while (mine[0] == '0') {
							mine.erase(0, 1);
						}
						if (mine.size() == 0) {
							mine[0] = '0';
						}
					}
				}
			}
		}
		else if (afirst[0] == '-' && sfirst[0] != '-') {
			if (afirst.size() < sfirst.size()) {
				swap(afirst, sfirst);
				swap(afl, sfl);
			}
			for (int i = 1; i <= sfirst.size(); i++) {
				k = afirst[afirst.size() - i] + sfirst[sfirst.size() - i] - 48;
				if (k >= 58)
				{
					afirst[afirst.size() - i - 1]++;
					afirst[afirst.size() - i] = k - 10;
				}
				else
					afirst[afirst.size() - i] = k;
			}
			if (a[0] == '-') {
				mine.replace(0, sfirst.size(), afirst);
				if (mine[0] == '-') {
					while (mine[1] == '0') {
						mine.erase(1, 2);
					}
					if (mine.size() == 1) {
						mine[0] = '0';
					}
				}
				else {
					while (mine[0] == '0') {
						mine.erase(0, 1);
					}
					if (mine.size() == 0) {
						mine[0] = '0';
					}
				}
			}
			else {
				mine = afirst;
				if (mine[0] == '-') {
					while (mine[1] == '0') {
						mine.erase(1, 2);
					}
					if (mine.size() == 1) {
						mine[0] = '0';
					}
				}
				else {
					while (mine[0] == '0') {
						mine.erase(0, 1);
					}
					if (mine.size() == 0) {
						mine[0] = '0';
					}
				}
			}
		}
	}
	int all = alast.size(), sll = slast.size();
	if (alast[0] == '-' && slast[0] == '-') {
		if (alast.size() > slast.size()) {
			swap(alast, slast);
			swap(all, sll);
			sign = -1;
		}
		if (alast.size() == slast.size()) {
			for (int i = 0; i < alast.size(); i++) {
				if (alast[i] != slast[i] && alast[i] > slast[i]) {
					swap(alast, slast);
					swap(all, sll);
					sign = -1;
				}
				if (alast[i] != slast[i] && alast[i] < slast[i]) {
					break;
				}
			}
		}
		for (int i = 1; i < alast.size(); i++)
		{
			k = slast[slast.size() - i] - alast[alast.size() - i] + 48;
			if (k < '0')
			{
				slast[slast.size() - i - 1]--;
				slast[slast.size() - i] = k + 10;
			}
			else
				slast[slast.size() - i] = k;
		}
		if (sign == -1) {
			mine1[0] = '-';
			mine1.replace(0, slast.size(), slast);
			if (mine1[0] == '-') {
				while (mine1[1] == '0') {
					mine1.erase(1, 1);
				}
			}
			else {
				while (mine1[0] == '0') {
					mine1.erase(0, 1);
				}
			}
		}
		else {
			mine1 = slast;
			if (mine1[0] == '-') {
				while (mine1[1] == '0') {
					mine1.erase(1, 2);
				}
				if (mine1.size() == 1) {
					mine1[0] = '0';
				}
			}
			else {
				while (mine1[0] == '0') {
					mine1.erase(0, 0);
				}
				if (mine1.size() == 0) {
					mine1[0] = '0';
				}
			}
		}

	}
	else if (alast[0] != '-' && slast[0] != '-') {
		if (alast.size() > slast.size()) {
			swap(alast, slast);
			swap(afl, sfl);
			sign = -1;
		}
		if (alast.size() == slast.size()) {
			for (int i = 0; i < alast.size(); i++) {
				if (alast[i] != slast[i] && alast[i] > slast[i]) {
					swap(alast, slast);
					swap(all, sll);
					sign = -1;
				}
				if (alast[i] != slast[i] && alast[i] < slast[i]) {
					break;
				}
			}
		}
		for (int i = 1; i <= alast.size(); i++)
		{
			k = slast[slast.size() - i] - alast[alast.size() - i] + 48;
			if (k < 48) {
				slast[slast.size() - i - 1]--;
				slast[slast.size() - i] = k + 10;
			}
			else
				slast[slast.size() - i] = k;
		}
		if (sign == -1) {
			mine1[0] = '-';
			mine1.replace(0, slast.size(), slast);
			if (mine1[0] == '-') {
				while (mine1[1] == '0') {
					mine1.erase(1, 2);
				}
				if (mine1.size() == 1) {
					mine1[0] = '0';
				}
			}
			else {
				while (mine1[0] == '0') {
					mine1.erase(0, 1);
				}
				if (mine1.size() == 1 && mine[0] == '-') {
					mine1[0] = '0';
				}
			}
		}
		else {
			mine1 = slast;
			if (mine1[0] == '-') {
				while (mine1[1] == '0') {
					mine1.erase(1, 2);
				}
				if (mine1.size() == 1) {
					mine1[0] = '0';
				}
			}
			else {
				while (mine1[0] == '0') {
					mine1.erase(0, 1);
				}
				if (mine1.size() == 0) {
					mine1[0] = '0';
				}
			}
		}
	}
	else {
		if (alast[0] != '-' && slast[0] == '-') {
			if (alast.size() > slast.size()) {
				swap(alast, slast);
				swap(all, sll);
			}
			for (int i = 1; i <= alast.size(); i++) {
				k = alast[alast.size() - i] + slast[slast.size() - i] - 48;
				if (k >= 58)
				{
					if (i == alast.length()) {
						if (k >= 58) {
							mine[mine.length() - 1]++;
							alast[alast.length() - i] = k - 10;
						}
					}
					else {
						alast[alast.length() - i - 1]++;
						alast[alast.length() - i] = k - 10;
					}
				}
				else
					alast[alast.size() - i] = k;
			}
			if (a[0] == '-') {
				mine1.replace(0, slast.size(), alast);
				if (mine1[0] == '-') {
					while (mine1[1] == '0') {
						mine1.erase(1, 2);
					}
					if (mine1.size() == 1) {
						mine1[0] = '0';
					}
				}
				else {
					while (mine1[0] == '0') {
						mine1.erase(0, 1);
					}
					if (mine1.size() == 0) {
						mine1[0] = '0';
					}
				}
			}
			else {
				mine1 = alast;
				if (mine1[0] == '-') {
					while (mine1[1] == '0') {
						mine1.erase(1, 2);
					}
					if (mine1.size() == 1) {
						mine1[0] = '0';
					}
				}
				else {
					if (mine1[0] == '-') {
						while (mine1[1] == '0') {
							mine1.erase(1, 2);
						}
						if (mine1.size() == 1) {
							mine1[0] = '0';
						}
					}
					else {
						while (mine1[0] == '0') {
							mine1.erase(0, 1);
						}
						if (mine1.size() == 0) {
							mine1[0] = '0';
						}
					}
				}
			}
		}
		else if (alast[0] == '-' && slast[0] != '-') {
			if (alast.size() < slast.size()) {
				swap(alast, slast);
				swap(all, sll);
			}
			for (int i = 1; i <= slast.size(); i++) {
				k = alast[alast.size() - i] + slast[slast.size() - i] - 48;
				if (k >= 58)
				{
					if (i == slast.length()) {
						if (k >= 58) {
							mine[mine.length() - 1]++;
							alast[alast.length() - i] = k - 10;
						}
					}
					else {
						alast[alast.length() - i - 1]++;
						alast[alast.length() - i] = k - 10;
					}
				}
				else
					alast[alast.size() - i] = k;
			}
			if (a[0] == '-') {
				mine1.replace(0, slast.size(), alast);
				if (mine1[0] == '-') {
					while (mine1[1] == '0') {
						mine1.erase(1, 2);
					}
					if (mine1.size() == 1) {
						mine1[0] = '0';
					}
				}
				else {
					while (mine1[0] == '0') {
						mine1.erase(0, 1);
					}
					if (mine1.size() == 0) {
						mine1[0] = '0';
					}
				}
			}
			else {
				mine1 = alast;
				if (mine1[0] == '-') {
					while (mine1[1] == '0') {
						mine1.erase(1, 2);
					}
					if (mine1.size() == 1) {
						mine1[0] = '0';
					}
				}
				else {
					while (mine1[0] == '0') {
						mine1.erase(0, 1);
					}
					if (mine1.size() == 0) {
						mine1[0] = '0';
					}
				}
			}
		}
	}
	for (int i = mine1.length() - 1; i >= 0; i--) {
		if (mine1[0] == '0' || mine1[0] == '-') {
			mine1.erase(0, 1);
		}
	}
	Mine = mine + mine1;
	Mine = Mine.replace(mine.size(), 0, ".");
	if (Mine[Mine.size() - 1] == '.') {
		Mine.erase(Mine.size() - 1, Mine.size());
	}
	return Mine;
}
string calfunc::Multiplication(string a, string s) {
	double ad, sd;
	bool dot1 = false, dot2 = false;
	string	Mult = "0";
	int k, sign1 = 1, sign2 = 1, length1, length2, location1, location2, ashar1 = 0, ashar2 = 0;
	length1 = a.size();
	length2 = s.size();
	if (length1 < 6 && length2 < 6) {
		ad = stod(a.substr().c_str());
		sd = stod(s.substr().c_str());
		Mult = to_string(ad * sd);
		for (int i = Mult.length() - 1; i >= 0; i--) {
			if (Mult[i] == '.') {
				location1 = i;
				break;
			}
		}
		for (int j = Mult.length() - 1; j > location1; j--) {
			if (Mult[j] == '0') {
				Mult.erase(j, j + 1);
			}
			else {
				break;
			}
		}
		if (Mult[Mult.size() - 1] == '.') {
			Mult.erase(Mult.size() - 1, Mult.size());
		}
		return Mult;
	}
	else {
		for (int i = 0; i < length1; i++) {
			if (a[i] == '.') {
				location1 = i;
				ashar1 = length1 - 1 - i;
				a.erase(location1, 1);
				break;
			}
		}
		while (a[0] == '0') {
			a.erase(0, 1);
		}
		if (a[0] == '-') {
			a.erase(0, 1);
			sign1 = -1;
		}
		for (int i = 0; i < length2; i++) {
			if (s[i] == '.') {
				location2 = i;
				ashar2 = length2 - 1 - i;
				s.erase(location2, 1);
				break;
			}
		}
		while (s[0] == '0') {
			s.erase(0, 1);
		}
		if (s[0] == '-') {
			s.erase(0, 1);
			sign2 = -1;
		}
		if (a.size() > s.size()) {
			swap(a, s);
		}
		for (int j = 1; j <= s.size(); j++) {
			string temp;
			for (int t = 1; t < j; t++) {
				temp = temp.replace(0, 0, "0");
			}
			for (int i = 1; i <= a.size(); i++) {
				temp = temp.replace(0, 0, "0");
				k = (s[s.size() - j] - 48) * (a[a.size() - i] - 48) + 48;
				temp[0] = k;
			}
			for (int w = temp.size() - 1; w >= 0; w--) {
				if (temp[w] > 57) {
					if (w == 0) {
						temp.replace(0, 0, "0");
						w++;
					}
					temp[w - 1] += ((temp[w] - 48) / 10);
					temp[w] = ((temp[w] - 48) % 10) + 48;
				}
			}
			Mult = Sum(Mult, temp);
		}
		if (sign1 * sign2 == -1) {
			Mult.replace(0, 0, "-");
		}
		if (!(ashar1 == 0 && ashar2 == 0)) {
			int p = (Mult.size() - (ashar1 + ashar2));
			while (p < 0) {
				Mult = Mult.replace(0, 0, "0");
			}
			Mult = Mult.replace(p, 0, ".");
			if (Mult[Mult.size() - 1] == '.') {
				Mult.erase(Mult.size() - 1, Mult.size());
			}
		}

		while (Mult[0] == '0') {
			Mult.erase(0, 1);
		}
		if (Mult.size() == 0) {
			Mult.replace(0, 0, "0");
		}
		if (Mult[0] == '.') {
			Mult = Mult.replace(0, 0, "0");
		}
		return Mult;
	}
}
string calfunc::Division(string a, string s) {
	double ad, sd;
	bool dot1 = false, dot2 = false;
	string	Divid, temp;
	int k, sign1 = 1, sign2 = 1, lengthdiv, length1, length2, finloc, location1, location2, ashar, ashar1 = 0, ashar2 = 0;
	length1 = a.size();
	length2 = s.size();
	if (length1 < 6 && length2 < 6) {
		if (s.size() == 1 && s[0] == '0') {//num/0
			return Divid.replace(0, 0, "error");
		}
		if (a.size() == 1 && a[0] == '0') {
			Divid = Divid.replace(0, 1, "0");
			return Divid;
		}
		ad = stod(a.substr().c_str());
		sd = stod(s.substr().c_str());
		Divid = to_string(ad / sd);
		for (int i = Divid.length() - 1; i >= 0; i--) {
			if (Divid[i] == '.') {
				location1 = i;
				break;
			}
		}
		for (int j = Divid.length() - 1; j > location1; j--) {
			if (Divid[j] == '0') {
				Divid.erase(j, j + 1);
			}
			else {
				break;
			}
		}
		if (Divid[Divid.size() - 1] == '.') {
			Divid.erase(Divid.size() - 1, Divid.size());
		}
		return Divid;
	}
	else {
		if (s.size() == 1 && s[0] == '0') {
			Divid = Divid.replace(0, 1, "error");
			return Divid;
		}
		if (a.size() == 1 && a[0] == '0') {
			Divid = Divid.replace(0, 1, "0");
			return Divid;
		}
		for (int i = 0; i < length1; i++) {
			if (a[i] == '.') {
				location1 = i;
				ashar1 = length1 - 1 - i;
				a.erase(location1, 1);
				break;
			}
			else
				ashar1 = 0;
		}
		while (a[0] == '0') {
			a.erase(0, 1);
		}
		if (a[0] == '-') {
			a.erase(0, 1);
			sign1 = -1;
		}
		for (int i = 0; i < length2; i++) {
			if (s[i] == '.') {
				location2 = i;
				ashar2 = length2 - 1 - i;
				s.erase(location2, 1);
				break;
			}
			else
				ashar2 = 0;
		}
		length1 = a.size();
		length2 = s.size();
		ashar = ashar1 - ashar2;
		while (s[0] == '0') {
			s.erase(0, 1);
		}
		if (s[0] == '-') {
			s.erase(0, 1);
			sign2 = -1;
		}
		while (a.size() < s.size()) {
			a.replace(a.size(), 0, "0");
			length1++;
			ashar++;
		}
		if (a.size() == s.size()) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != s[i] && a[i] < s[i]) {
					a.replace(a.size(), 0, "0");
					length1++;
					ashar++;
				}
				if (a[i] != s[i] && a[i] > s[i]) {
					break;
				}
			}
		}
		temp = a.substr(0, length2);
		for (int i = length2; i < length1 + 6; i++) {
			k = 0;
			Divid.replace(0, 0, "0");
			while (temp[0] != '-') {
				temp = Minus(temp, s);
				for (int w = temp.size() - 1; w >= 0; w--) {
					if (temp[w] > 57) {
						if (w == 0) {
							temp.replace(0, 0, "0");
							w++;
						}
						temp[w - 1] += ((temp[w] - 48) / 10);
						temp[w] = ((temp[w] - 48) % 10) + 48;
					}
				}
				k++;
			}
			Divid[0] = k - 1 + '0';
			temp.erase(0, 1);
			temp = Minus(s, temp);
			for (int w = temp.size() - 1; w >= 0; w--) {
				if (temp[w] > 57) {
					if (w == 0) {
						temp.replace(0, 0, "0");
						w++;
					}
					temp[w - 1] += ((temp[w] - 48) / 10);
					temp[w] = ((temp[w] - 48) % 10) + 48;
				}
			}
			if (i >= length1 && temp.size() == 1 && temp[0] == '0') {
				break;
			}
			if (i < length1)
				temp.replace(temp.size(), 0, a.substr(i, 1));
			else {
				temp.replace(temp.size(), 0, "0");
				if (i != length1 + 1)//?
					ashar++;
			}
			for (int w = temp.size() - 1; w >= 0; w--) {
				if (temp[w] > 57) {
					if (w == 0) {
						temp.replace(0, 0, "0");
						w++;
					}
					temp[w - 1] += ((temp[w] - 48) / 10);
					temp[w] = ((temp[w] - 48) % 10) + 48;
				}
			}
		}
		lengthdiv = Divid.size();
		for (int i = 0; i < lengthdiv / 2; i++) {
			swap(Divid[i], Divid[lengthdiv - i - 1]);
		}
		if (ashar != 0) {
			if (lengthdiv - ashar > 0)
				Divid.replace(lengthdiv - ashar, 0, ".");
			else {
				for (int i = 0; i < -(lengthdiv - ashar); i++) {
					Divid.replace(0, 0, "0");
				}
				Divid.replace(0, 0, "0.");
			}
		}
		if (sign1 * sign2 == -1) {
			Divid.replace(0, 0, "-");
		}
		if (Divid[0] == '0' && Divid[1] != '.') {
			while (Divid[0] == '0') {
				Divid.erase(0, 1);
			}
		}
		for (int j = 0; j < Divid.length(); j++) {
			if (Divid[j] == '.') {
				finloc = j;
				break;
			}
		}
		for (int f = Divid.length() - 1; f > finloc; f--) {
			if (Divid[Divid.length() - 1] == '0') {
				Divid.erase(Divid.length() - 1, Divid.length());
			}
		}
		if (Divid[Divid.length() - 1] == '.') {
			Divid.erase(Divid.length() - 1, Divid.length());
		}
		return Divid;
	}
}
string calfunc::calculator(string z)
 {
	int length = 0, n, n1, n2, j = 0, t = 0, k = 0, last = 0, amallocation, first = 30, parbaz = 0, parbaste = 0;//n=tedade characteraye beine parantez
	bool sik = false, check = false;
	char c;
	string	javab, num1, num2;
	z.replace(0, 0, "(");
	z.replace(z.size(), 0, ")");
	length = z.size();
	for (int j = 0; j < length; j++) {
		if (z[j] == '(') {
			parbaz++;
		}
		else if (z[j] == ')') {
			parbaste++;
		}
	}
	if (parbaz != parbaste) {
		cout << "error";
		return 0;
	}
	while (true) {//sik zadane parantez ha
		sik = false;
		if (z[j] != '(') {
			sik = true;
			break;
		}
		if (sik == true) {
			break;
		}
		for (int i = 0; i < length; i++) {
			first = length;
			last = 0;
			if (z[i] == ')') {
				last = i;
				for (int j = i; j >= 0; j--) {
					if (z[j] == '(') {
						first = j;
						break;
					}
				}
			}
			n = 0;
			if (first != length) {
				n = last - (first + 1);
				break;
			}
		}
		for (int i = first + 1; i < last; i++) {
			check = false;
			if (z[i] == '*' || z[i] == '/') {
				if (z[i] == '-' && z[i - 1] == '(') {
					i++;
				}
				else {
					amallocation = i;
					c = z[i];
					for (int i = amallocation - 1; i >= 0; i--) {
						if (z[i] == '+' || z[i] == '-' || z[i] == '*' || z[i] == '/' || z[i] == '(') {
							if (z[i] == '-' && z[i - 1] == '(')//(-num)
								i--;
							first = i;
							break;
						}
					}
					for (int i = amallocation + 2; i < length; i++) {//+2...(num opp -num)
						if (z[i] == '+' || z[i] == '-' || z[i] == '*' || z[i] == '/' || z[i] == ')') {
							last = i;
							n = last - (first + 1);
							break;
						}
					}
					n1 = i - first;
					n2 = last - i;
					num1 = z.substr(first + 1, n1 - 1);
					num2 = z.substr(i + 1, n2 - 1);
					check = true;
					break;
				}
			}
		}
		if (check == false) {
			for (int i = first + 1; i < last; i++) {
				check = false;
				if (z[i] == '+' || z[i] == '-') {
					if (z[i] == '-' && z[i - 1] == '(') {
						i++;
					}
					else {
						amallocation = i;
						c = z[i];
						for (int i = amallocation - 1; i >= 0; i--) {
							if (z[i] == '+' || z[i] == '-' || z[i] == '*' || z[i] == '/' || z[i] == '(') {
								if (z[i] == '-' && z[i - 1] == '(')//(-num)
									i--;
								first = i;
								break;
							}
						}
						for (int i = amallocation + 2; i < length; i++) {//+2...(num opp -num)
							if (z[i] == '+' || z[i] == '-' || z[i] == '*' || z[i] == '/' || z[i] == ')') {
								last = i;
								n = last - (first + 1);
								break;
							}
						}
						n1 = i - first;
						n2 = last - i;
						num1 = z.substr(first + 1, n1 - 1);
						num2 = z.substr(i + 1, n2 - 1);
						check = true;
						break;
					}
				}
			}
		}
		javab = z.substr(first + 1, n);
		switch (c) {
		case'+':
			javab = Sum(num1, num2);
			break;
		case'-':
			javab = Minus(num1, num2);
			break;
		case'*':
			javab = Multiplication(num1, num2);
			break;
		case'/':
			javab = Division(num1, num2);
			if (javab == "error") {
				cout << "error";
				return 0;
			}
			break;
		case '-52':
			break;
		}
		if (z[first] == '(' && z[last] == ')') {
			z.replace(first, n + 2, javab);
		}
		else {
			z.replace(first + 1, n, javab);
		}
	}
	for (int i = 0; i < z.size(); i++) {
		if (z[i] == '.') {
			z = z.substr(0, i + 6);
			break;
		}
	}
	return z;
}
double calfunc::radical(double x, int a) {
	double tavan1 = 1, radical = 0;
	for (int j = 1; j < 6; j++) {
		while (x >= Pow(radical, a)) {
			radical += tavan1;
		}
		radical -= tavan1;
		tavan1 /= 10;
	}
	return radical;
}
long int calfunc::factorial(int x) {
	int fact = 1;
	if (x == 0) {
		return 1;
	}
	else {
		for (int i = x; i > 0; i--) {
			fact *= i;
		}
		return fact;
	}
}
double calfunc::logarithm(double x, int a) {
	double log = 0;
	log = Ln(x) / Ln(a);
	return log;
}
double calfunc::Ln(double x) {
	double ln = 0, y = 0;
	for (int i = 1; i <= 9999; i += 2) {
		y += (Pow(((x - 1) / (x + 1)), i)) / (i);
	}
	ln = 2 * y;
	return ln;
}
double calfunc::Pow(double x, int a) {
	double t = 1;
	for (int i = 1; i <= a; i++) {
		t *= x;
	}
	return t;
}
double calfunc::sine(double x) {
	double sin = 0;
	int sign = 1;
	for (int i = 1; i <= 15; i += 2) {
		sin += sign * ((Pow(x, i)) / (factorial(i)));
		sign *= -1;
	}
	return sin;
}
double calfunc::cosine(double x) {
	double cos = 1;
	int sign = -1;
	for (int i = 2; i <= 14; i += 2) {
		cos += sign * ((Pow(x, i)) / (factorial(i)));
		sign *= -1;
	}
	return cos;
}
double calfunc::tangent(double x) {
	double tan = 0;
	tan = (sine(x)) / (cosine(x));
	return tan;
}
double calfunc::cotangent(double x) {
	double cot = 0;
	cot = (cosine(x)) / (sine(x));
	return cot;
}