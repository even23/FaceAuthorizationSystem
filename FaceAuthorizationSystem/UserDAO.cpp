#include "UserDAO.h"
#include "Utils.h"

UserDAO::UserDAO()
{
	users = new vector<User*>();
	filename = USER_FILENAME;
	isModified = false;
	read_csv();
}

UserDAO::~UserDAO()
{
	write_csv();
	delete users;
}

void UserDAO::read_csv(char separator) {
	ifstream file(filename.c_str());
	//if (!file) {
	//	string error_message = "No valid input file was given, please check the given filename.";
	//	CV_Error(Error::StsBadArg, error_message);
	//}
	string line;
	string id;
	string name;
	string surname;
	string login;
	string password;
	string photos;
	getline(file, headers);
	while (getline(file, line)) {
		stringstream liness(line);
		getline(liness, id, separator);
		getline(liness, name, separator);
		getline(liness, surname, separator);
		getline(liness, login, separator);
		getline(liness, password, separator);
		getline(liness, photos);
		users->push_back(new User(atoi(id.c_str()), name, surname, login, password, atoi(photos.c_str())));
	}
	file.close();
}

void UserDAO::write_csv(char separator)
{
	ofstream file(filename);
	file << headers << endl;
	for (vector<User*>::iterator user = users->begin(); user != users->end(); ++user) {
		file << getCsvRow(*user, separator) << endl;
	}
	file.close();
}

string UserDAO::getCsvRow(User* user, char separator)
{
	stringstream result;
	result << user->getId() << separator
		<< user->getName() << separator
		<< user->getSurname() << separator
		<< user->getLogin() << separator
		<< user->getPassword() << separator
		<< user->getPhotos();
	return result.str();
}

User* UserDAO::getUserByLogin(string login) {
	for (vector<User*>::iterator user = users->begin(); user != users->end(); ++user) {
		if ((*user)->getLogin() == login) {
			return *user;
		}
	}
	return nullptr;
}

User* UserDAO::addUser(string name, string surname, string login, string password)
{
	int id = users->back()->getId() + 1;
	User* user = new User(id, name, surname, login, password, 0);
	users->push_back(user);

	string folderCreateCommand = "mkdir " + PhotoDAO::PHOTO_DIR + to_string(user->getId());
	system(folderCreateCommand.c_str());

	write_csv();

	return user;
}

void UserDAO::removeUser(User * _user)
{
	for (vector<User*>::iterator user = users->begin(); user != users->end(); ++user) {
		if ((*user) == _user) {
			users->erase(user);
			break;
		}
	}
	write_csv();
	string folderCreateCommand = "rmdir /s /q " + PhotoDAO::PHOTO_DIR + to_string(_user->getId());
	system(folderCreateCommand.c_str());
}
