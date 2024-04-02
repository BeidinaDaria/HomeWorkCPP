#include "Proxy.h"

std::string Proxy::read(int i) {
	std::stack<Str> buf;
	Str s;
	if (!buffer.empty()) {
		s = buffer.top();
		while (s.getNum() != i) {
			buf.push(s);
			buffer.pop();
			if (buffer.empty()) break;
			s = buffer.top();
		}
	}
	if (s.getNum() == i) {
		while (!buf.empty()) {
			buffer.push(buf.top());
			buf.pop();
		}
		buffer.push(s);
		return s.getStr();
	}
	s=Str(fs.readFile(i),i);
	if ((buffer.size() >= maxSize)&&(s.getStr()!="")) {
		std::stack<Str> buf;
		for (int j = 1; j < maxSize; j++) {
			buf.push(buffer.top());
			buffer.pop();
		}
		buffer.pop();
		for (int j = 1; j < maxSize; j++) {
			buffer.push(buf.top());
			buf.pop();
		}
		buffer.push(s);
	}
	return s.getStr();
}

void Proxy::write(std::string s, int j) {
	fs.writeFile(s, j);
}