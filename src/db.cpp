////////////////////////////////////////////////////////
//
// ECE 3574, A5, Walter Pereira Cruz
// File name: db.cpp
// Description: Contains the implementations for the Database class
// functions
//				
// Date:        03/14/2025
//
#include "db.h"
#include <fstream>
#include <iomanip>

Database* Database::instance = nullptr;

Database::~Database() {
	if (connected) {
		disconnect();
	}
}

Database* Database::getInstance(const std::string& dbName, const std::string& usrname, const std::string& pasword) {
	if (!instance) {
		instance = new Database(dbName, usrname, pasword);
	}
	else {
		if (instance->db != dbName || instance->username != usrname || instance->password != pasword) {
			throw std::runtime_error("invalid database name, username, or password");
		}
	}
	return instance;
}

void Database::connect() {
	connected = true;
}

void Database::disconnect() {
	connected = false;
}

bool Database::isConnected() {
	return connected;
}


void* Database::operator new(size_t size) {
	std::cout << "overloaded new ";
	void* ptr = std::malloc(size);
	if (!ptr) {
		throw std::bad_alloc();
	}
	return ptr;
}

void Database::operator delete(void* pt) {
	std::cout << "overloaded delete ";
	std::free(pt);
}

void Database::set_username(const std::string& usrname) {
	username = usrname;
}

void Database::set_password(const std::string& pasword) {
	password = pasword;
}

std::string Database::get_username() {
	return username;
}


std::string Database::get_password() {
	return password;
}

void Database::resetInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}