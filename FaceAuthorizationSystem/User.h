#pragma once

#include <iostream>
#include <stdio.h>

using namespace std;

class User
{
public:
	User(int id, string name, string surname, string login, string password, int photos)
		:id(id), name(name), surname(surname), login(login), password(password), photos(photos)
	{}

	~User();

	int getId() { return id; }
	string getName() { return name; }
	string getSurname() { return surname; }
	string getLogin() { return login; }
	string getPassword() { return password; }

	void setName(string _name) { name = _name; }
	void setSurname(string _surname) { surname = _surname; }
	void setLogin(string _login) { login = _login; }
	void setPassword(string _password) { password = _password; }

	int getPhotos() { return photos; }
	int addPhoto() {
		return photos++;
	}

private:
	int id;
	string name;
	string surname;
	string login;
	string password;
	int photos;
};

