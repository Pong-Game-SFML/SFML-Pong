<<<<<<< HEAD
#include "TextBox.h"
void TextBox::setTextBox(int size, Color color, bool sel)
{
	textBox.setCharacterSize(size);
	textBox.setFillColor(color);
	isSelected = sel;
	if (sel)
	{
		textBox.setString("_");
	}
	else
	{
		textBox.setString("");
	}
}

void TextBox::inputLogic(int charTyped)
{
	if (charTyped != DELETEKEY && charTyped != ENTERKEY && charTyped != ESCAPEKEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETEKEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textBox.setString(text.str() + "_");
}

void TextBox::deleteLastChar()
{
	string t = text.str();
	string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textBox.setString(text.str());
}

void TextBox::setFont(Font& font)
{
	textBox.setFont(font);
}

void TextBox::setPosition(Vector2f pos)
{
	textBox.setPosition(pos);
}

void TextBox::setLimit(bool existLimit)
{
	hasLimit = existLimit;
}

void TextBox::setLimit(bool existLimit, int lim)
{
	hasLimit = existLimit;
	limit = lim;
}

string TextBox::getText()
{
	return text.str();
}

void TextBox::draw(RenderWindow& window)
{
	window.draw(textBox);
}

void TextBox::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (charTyped == ENTERKEY)
			{
				limit = 0;
			}
			else
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETEKEY)
					{
						deleteLastChar();
					}

				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}
}

int TextBox::getLimit()
{
	return limit;
=======
#include "TextBox.h"



void TextBox::setTextBox(int size, Color color, bool sel)
{
	textBox.setCharacterSize(size);
	textBox.setFillColor(color);
	isSelected = sel;
	if (sel)
	{
		textBox.setString("_");
	}
	else
	{
		textBox.setString("");
	}
}

void TextBox::inputLogic(int charTyped)
{
	if (charTyped != DELETEKEY && charTyped != ENTERKEY && charTyped != ESCAPEKEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETEKEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textBox.setString(text.str() + "_");
}

void TextBox::deleteLastChar()
{
	string t = text.str();
	string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;
	textBox.setString(text.str());
}

void TextBox::setFont(Font& font)
{
	textBox.setFont(font);
}

void TextBox::setPosition(Vector2f pos)
{
	textBox.setPosition(pos);
}

void TextBox::setLimit(bool ToF)
{
	hasLimit = ToF;
}

void TextBox::setLimit(bool ToF, int lim)
{
	hasLimit = ToF;
	limit = lim;
}

void TextBox::setSelected(bool sel)
{
	isSelected = sel;
	// If not selected, remove the '_' at the end:
	if (!sel)
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}	
		textBox.setString(newT);
	}
}

string TextBox::getText()
{
	return text.str();
}

void TextBox::draw(RenderWindow& window)
{
	window.draw(textBox);
}

void TextBox::typedOn(Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128 )
		{
			if (charTyped == ENTERKEY)
			{
				limit = 0;
			}
			else
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETEKEY)
					{
						deleteLastChar();
					}

				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}
}

int TextBox::getLimit()
{
	return limit;
>>>>>>> 5373421147b1b1efdbbe9f0476782e5e2a1f9dc0
}