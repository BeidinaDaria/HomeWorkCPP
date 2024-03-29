#include "Calculator.h"
#include <string>


Calculator::Calculator() :
	window(sf::VideoMode(398, 598), "i-calculator"),
	gray(200, 200, 200, 255),
	white(20, 20, 20, 255),
	orange(198, 114, 57, 255)
{
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			sf::Color setColor = (i == 1 || j == 3) ? orange : gray;
			keybord.push_back(
				Button(sf::Vector2f(98, 98),
					setColor,
					sf::Vector2f(j * 100, i * 100),
					keyboardText[i - 1][j])
			);
		}
	}
	font.loadFromFile("arialbd.ttf");
	text.setFont(font);
	text.setCharacterSize(70);
	text.setString(fieldText);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(350, 5));

	//button(sf::Vector2f(98,98), gray, sf::Vector2f(200,200))

}

void Calculator::run() {
	while (window.isOpen())
	{
		processEvent();
		update();
		render();
	}

}

void Calculator::update()
{
	for (auto& key : keybord) {
		key.update();
	}
	text.setString(fieldText);
	text.setPosition(sf::Vector2f(
		365 - fieldText.size() * 38,
		text.getPosition().y
	));
}

void Calculator::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
			event.type == sf::Event::MouseButtonReleased)
		{
			std::cout << "mouse is pressed" << std::endl;
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			for (auto& key : keybord) {
				if ((mousePos.x >= key.getPosition().x) &&
					(mousePos.x <= (key.getPosition().x + key.getSize().x)) &&
					(mousePos.y >= key.getPosition().y) &&
					(mousePos.y <= (key.getPosition().y + key.getSize().y))) {
					key.changeActive();

					if (event.type == sf::Event::MouseButtonReleased) {
						if (key.getText()[0] >= '0' && key.getText()[0] <= '9' ||
							key.getText()[0] == '.') {
							if (fieldText == "0" && key.getText() != ".") fieldText = "";
							if (key.getText() == "." &&
								fieldText.find(".") <= fieldText.size()) {
								break;
							}
							fieldText += key.getText();
						}
						else {
							if (key.getText()[0] == '=') {
								fieldText = std::to_string(res());
							}
							else {
								if (key.getText() == "C") {
									fieldText = "0";
								}
								if (key.getText() == "sqrt") {
									fieldText += "v";
								}
								else if (key.getText() == "X^") {
									fieldText += "^";
									}
									else fieldText += key.getText();
							}
						}

					}
				}
			}

		}

	}
}

void Calculator::render()
{
	window.clear();
	for (auto el : keybord) {
		el.draw(window);
	}

	window.draw(text);
	window.display();
}

double Calculator::res() {
	int c = 0, op = 0,i=0;
	double res = 0;
	bool f = true;
	while (i < std::size(fieldText)) {
		if ((fieldText[i] >= '0') && (fieldText[i] <= '9')||(fieldText[i]=='.')){
			c++;
		}
		else {
			switch (op) {
				case(1):res += stod(fieldText.substr(i-c,i));
					break;
				case(2):res -= stod(fieldText.substr(i - c , i));
					break;
				case(3):res *= stod(fieldText.substr(i - c, i));
					break;
				case(4):res /= stod(fieldText.substr(i - c, i));
					break;
				case(5):res = std::pow(res, stod(fieldText.substr(i - c, i)));
					break;
				case(6):res = std::sqrt(stod(fieldText.substr(i - c, i)));
					break;
				default:res = stod(fieldText.substr(i - c, i));
			}
			c = 0;
			if (fieldText[i] == '+')
				op = 1;
			if (fieldText[i] == '-')
				op = 2;
			if (fieldText[i] == '*')
				op = 3;
			if (fieldText[i] == '/')
				op = 4;
			if (fieldText[i] == '^')
				op = 5;
			if (fieldText[i] == 'v')
				op = 6;
		}
		i++;
	}
	switch (op) {
		case(1):res += stod(fieldText.substr(i - c, i));
			break;
		case(2):res -= stod(fieldText.substr(i - c, i));
			break;
		case(3):res *= stod(fieldText.substr(i - c, i));
			break;
		case(4):res /= stod(fieldText.substr(i - c, i));
			break;
		case(5):res = std::pow(res, stod(fieldText.substr(i - c, i)));
			break;
		case(6):res = std::sqrt(stod(fieldText.substr(i - c, i)));
			break;
		default:res = stod(fieldText.substr(i - c, i));
	}
	return res;
}
