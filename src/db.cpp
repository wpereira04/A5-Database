﻿////////////////////////////////////////////////////////
//
// ECE 3574, A5, Walter Pereira Cruz
// File name: db.cpp
// Description: Contains the implementations for the Database class
// functions
//				
// Date:        03/14/2025
//
#include "db.h"

// intializes instance to nullptr

Database* Database::instance = nullptr;

// default destructor
Database::~Database() {

}

// checks if the instance is occupied which determines if it's "the first run" or not. 
// creates an instance and returns it or checks for matching information and either returns the instance
// or throws a runtime error.
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

// sets connected to true
void Database::connect() {
	connected = true;
}

// sets connected to false
void Database::disconnect() {
	connected = false;
}

// returns the state of connected
bool Database::isConnected() {
	return connected;
}

// override the new operator with new definition
void* Database::operator new(size_t size) {
	std::cout << "overloaded new ";
	void* ptr = std::malloc(size);
	if (!ptr) {
		throw std::bad_alloc();
	}
	return ptr;
}

// override the delete operator with another definition
void Database::operator delete(void* pt) {
	std::cout << "overloaded delete ";
	std::free(pt);
}

// sets the username member variable
void Database::set_username(const std::string& usrname) {
	username = usrname;
}

// sets the password member variable
void Database::set_password(const std::string& pasword) {
	password = pasword;
}

// gets the username member variable
std::string Database::get_username() {
	return username;
}

// gets the password member variable
std::string Database::get_password() {
	return password;
}

// reset the instance
void Database::resetInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}