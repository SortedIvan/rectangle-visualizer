#pragma once

#define COLOR_MAX 1
#define COLOR_MIN 200

struct Canvas {
	int width;
	int height;
	Canvas(int width, int height) {
		this->width = width;
		this->height = height;
	}
};

struct SysRect {
	int width;
	int height;
	int x;
	int y;
	sf::Color color;

	SysRect(int width, int height, int x, int y) {
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
	}
};

class SysRectFactory {
public:
	SysRect CreateRect(int x, int y, int width, int height) {
		SysRect rect = SysRect(width, height, x, y);
		rect.color = RandColorGenerator();
		return rect;
	}

	void DrawAllRects(sf::RenderWindow& window, std::vector<SysRect>& rects) {
		for (int i = 0; i < rects.size(); ++i) {
			sf::RectangleShape rect;
			rect.setFillColor(rects[i].color);
			rect.setPosition(rects[i].x, rects[i].y);
			rect.setSize(sf::Vector2f(rects[i].width, rects[i].height));
			window.draw(rect);
		}
	}

private:
	sf::Color RandColorGenerator() {
		int r = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MAX;
		int b = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MAX;
		int g = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MAX;
		return sf::Color(r, b, g);
	}
};