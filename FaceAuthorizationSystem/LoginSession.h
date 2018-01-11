#pragma once
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;
using namespace cv;

class LoginSession
{
public:
	LoginSession(string login, int userId, string userPassword, string typedPassword, Mat photo) :
		login(login), userId(userId), userPassword(userPassword), typedPassword(typedPassword), photo(photo) {
	}
	~LoginSession();

	int getUserId() { return userId; }
private:
	string login;
	int userId;
	string userPassword;
	string typedPassword;
	Mat photo;
};
